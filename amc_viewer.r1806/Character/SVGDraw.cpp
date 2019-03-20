#include "SVGDraw.hpp"
#include <Graphics/Graphics.hpp>
#include <Vector/Vector.hpp>
#include <Vector/VectorGL.hpp>
#include <Vector/Quat.hpp>
#include <Library/Skeleton.hpp>
#include <algorithm>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;

using std::ostringstream;

using std::sort;

using std::vector;

class GLMatrix {
public:
	Vector4f x,y,z,w;
	Vector4f transform(Vector4f const &in) {
		return x * in.x + y * in.y + z * in.z + w * in.w;
	}
};

template< class FOO >
Vector2f to_screen( FOO const &in ) {
	return make_vector(
		(in.x + 1.0f) * 0.5f * Graphics::screen_x,
		(1.0f - in.y) * 0.5f * Graphics::screen_y
			);
}

template< class FOO >
Vector2f to_screen_vec( FOO const &in ) {
	return make_vector(
		 in.x * 0.5f * Graphics::screen_x,
		-in.y * 0.5f * Graphics::screen_y
			);
}

string svg_color(Vector3f const &color) {
	ostringstream col;
	col << "rgb(" << 100 * color.r << "%, " << 100 * color.g << "%, " << 100 * color.b << "%)";
	return col.str();
}

class Cylinder {
public:
	Vector2f a1,a2; //screen-space axis
	Vector2f close_to_light; //direction -- of nearest rim point to light
	Vector3f base; //screen-space base (w/ depth)
	Vector3f along; //screen-space direction (w/ depth)
	Vector3f color;
	bool shadow; //is this a squished / shadow cylinder?
	bool lit;
	float light_cap; //amount of light cap at base is getting.
	float light_rim; //amount of light rim is getting (at close_to_light).
	float ambient;
	void draw(ostream &svg_file) const {
		static unsigned int gind = 0;
		float ang_a1 = atan2f(a1.y, a1.x) * 180.0f / float(M_PI);
		bool sweep = (perpendicular(a1) * along.xy) > 0;
		//Far cap arc and sides.
		if (lit) {
			Vector2f c = close_to_light;
			if (c * along.xy < 0.0f) {
				float a = c * normalize(along.xy);
				float p = c * perpendicular(normalize(along.xy));
				if (p < 0.0f) p = -2.0f * length(a1) - p;
				else p =  2.0f * length(a1) - p;
				c = a * normalize(along.xy) + p * perpendicular(normalize(along.xy));
			}
			svg_file << "<defs>\n<linearGradient id=\"grad" << gind << "\" x1=\"" << base.x + c.x - a1.x << "\" y1=\"" << base.y + c.y - a1.y << "\" x2=\"" << base.x + c.x + a1.x << "\" y2=\"" << base.y + c.y + a1.y << "\" gradientUnits=\"userSpaceOnUse\">\n";
			for (unsigned int a = 0; a <= 5; ++a) {
				float per = a / 5.0f;
				float amt = cosf((0.5f - per) * float(M_PI)) * light_rim + ambient;
				svg_file << "<stop offset=\"" << 100 * per << "%\" stop-color=\"" << svg_color(amt * color) << "\" />\n";

			}
			svg_file << "</linearGradient>\n</defs>\n";
		}
		svg_file << "<path d=\""
			<< "M " << base.x + a1.x << ',' << base.y + a1.y << ' '
			<< "L " << base.x + along.x + a1.x << ' ' << base.y + along.y + a1.y << ' '
			<< "A " << length(a1) << ',' << length(a2) << ' ' << ang_a1 << ' ' << 0 << ' ' << sweep << ' ' << base.x + along.x - a1.x << ',' << base.y + along.y - a1.y << ' '
			<< "L " << base.x - a1.x << ',' << base.y - a1.y << ' '
			<< "\" fill=\"";
			if (!lit) {
				svg_file << svg_color(color);
			} else {
				svg_file << "url(#grad" << gind << ")";
			}
			svg_file << "\"/>\n";
		Vector3f cap_color = color;
		if (lit) cap_color *= light_cap + ambient;
		Vector2f p = a2;
		if (p * perpendicular(a1) > 0) p *= -1.0f;
		//Near cap arc:
		svg_file << "<path d=\""
			<< "M " << base.x + a1.x << ' ' << base.y + a1.y << ' '
			<< "A " << length(a1) << ',' << length(a2) << ' ' << ang_a1 << ' ' << 0 << ' ' << '1' << ' ' << base.x - p.x << ',' << base.y - p.y << ' '
			<< "A " << length(a1) << ',' << length(a2) << ' ' << ang_a1 << ' ' << 0 << ' ' << '1' << ' ' << base.x - a1.x << ',' << base.y - a1.y << ' '
			<< "A " << length(a1) << ',' << length(a2) << ' ' << ang_a1 << ' ' << 0 << ' ' << '1' << ' ' << base.x + p.x << ',' << base.y + p.y << ' '
			<< "A " << length(a1) << ',' << length(a2) << ' ' << ang_a1 << ' ' << 0 << ' ' << '1' << ' ' << base.x + a1.x << ',' << base.y + a1.y << ' '
			<< "\" fill=\"" << svg_color(cap_color) << "\"/>\n";
		if (lit) {
			++gind;
		}
	}
	bool operator<(Cylinder const &other) const {
		//draw first if shadow and other isn't.
		if (shadow && !other.shadow) {
			return true;
		}
		//draw first if larger z.
		if (base.z == other.base.z) {
			return along.z > other.along.z;
		}
		return base.z > other.base.z;
	}
};

vector< Cylinder > scene;

void Character::start_draw(ostream &svg_file) {
	scene.clear();
	svg_file << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
	svg_file << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	svg_file << "<svg width=\"" << Graphics::screen_x << "px\" height=\"" << Graphics::screen_y << "px\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n";
}

void Character::draw(ostream &svg_file, Pose const &pose, State const &state, bool detail, bool color) {
	GLMatrix modelview, projection;

	glPushMatrix();
	glTranslate(state.position);
	glRotatef(state.orientation * 180.0f / (float)M_PI, 0.0f, 1.0f, 0.0f);

	glGetFloatv(GL_MODELVIEW_MATRIX, (float *)(&modelview));
	glGetFloatv(GL_PROJECTION_MATRIX, (float *)(&projection));

	glPopMatrix();

	if (projection.x.w != 0.0f
	 || projection.y.w != 0.0f
	 || projection.z.w != 0.0f
	 || projection.w.w != 1.0f) {
		cout << "projection matrix contains divide-y bit:\n"
			<< '\t' << projection.x << "\n"
			<< '\t' << projection.y << "\n"
			<< '\t' << projection.z << "\n"
			<< '\t' << projection.w << endl;
	}
	if (modelview.x.w != 0.0f
	 || modelview.y.w != 0.0f
	 || modelview.z.w != 0.0f
	 || modelview.w.w != 1.0f) {
		cout << "modelview matrix contains divide-y bit:\n"
			<< '\t' << modelview.x << "\n"
			<< '\t' << modelview.y << "\n"
			<< '\t' << modelview.z << "\n"
			<< '\t' << modelview.w << endl;
	}

	Vector4f pos = make_vector(state.position, 1.0f);
	pos = projection.transform(modelview.transform(pos));
	pos.xy = to_screen(pos.xy);

	vector< int > parent_stack;
	vector< Quatf > orientation_stack;
	vector< Vector3f > position_stack;

	parent_stack.push_back(-1);
	orientation_stack.push_back(pose.root_orientation);
	position_stack.push_back(pose.root_position);

	assert(pose.skeleton);

	for (unsigned int b = 0; b < pose.bone_orientations.size(); ++b) {
		while(!parent_stack.empty() && parent_stack.back() != pose.skeleton->bones[b].parent) {
			orientation_stack.pop_back();
			position_stack.pop_back();
			parent_stack.pop_back();
		}
		assert(!parent_stack.empty());

		//orientation_stack gets bone rotation:
		orientation_stack.push_back(normalize(multiply(orientation_stack.back(), pose.bone_orientations[b])));

		//rotation from default cylinder to bone:
		Quatf to_direction = rotation(make_vector(0.0f, 0.0f, 1.0f), make_vector< float >(pose.skeleton->bones[b].direction));
		//...to character space:
		to_direction = multiply(orientation_stack.back(), to_direction);

		//set up a basic cylinder:
		Vector3f along = make_vector(0.0f, 0.0f, 1.0f);
		Vector3f r1 = make_vector(1.0f, 0.0f, 0.0f);
		Vector3f r2 = make_vector(0.0f, 1.0f, 0.0f);
		//scale to bone size:
		along *= pose.skeleton->bones[b].length;
		r1 *= pose.skeleton->bones[b].radius;
		r2 *= pose.skeleton->bones[b].radius;
		//rotate to bone orientation:
		along = rotate(along, to_direction);
		r1 = rotate(r1, to_direction);
		r2 = rotate(r2, to_direction);

		//transform to eye space:
		Vector3f base = position_stack.back();
		base = modelview.transform(make_vector( base, 1.0f )).xyz;
		along = modelview.transform(make_vector( along, 0.0f )).xyz;
		r1 = modelview.transform(make_vector( r1, 0.0f )).xyz;
		r2 = modelview.transform(make_vector( r2, 0.0f )).xyz;
		//figure out lighting in eye space:
		bool lit = false;
		float light_cap = 1.0f;
		float light_rim = 1.0f;
		float ambient = 0.0f;
		Vector3f close_to_light = make_vector(0.0f, 0.0f, 0.0f);
		if (glIsEnabled(GL_LIGHTING)) {
			lit = true;
			Vector4f light = make_vector(0.0f, 0.0f, 0.0f, 0.0f);
			glGetLightfv(GL_LIGHT0, GL_POSITION, light.c);
			if (light.w != 0.0f) {
				cout << "Warning: light may be inaccurate!" << endl;
			}
			light.xyz = normalize(light.xyz);
			light_cap = -normalize(along) * light.xyz;
			if (light_cap < 0.0f) light_cap = 0.0f;
			close_to_light = r1 * (normalize(r1) * light.xyz) + r2 * (normalize(r2) * light.xyz);
			if (r1 * r2 > 0.0001f) {
				cout << "Non-perpendicularity problem..." << endl;
			}
			light_rim = normalize(close_to_light) * light.xyz;
			if (light_rim < 0.0f) light_rim = 0.0f;

			Vector4f light_color = make_vector(0.0f, 0.0f, 0.0f, 0.0f);
			Vector4f light_ambient = make_vector(0.0f, 0.0f, 0.0f, 0.0f);
			glGetLightfv(GL_LIGHT0, GL_DIFFUSE, light_color.c);
			glGetLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient.c);
			ambient = (light_ambient.r + light_ambient.g + light_ambient.b) / 3.0f;
			light_cap *= (light_color.r + light_color.g + light_color.b) / 3.0f;
			light_rim *= (light_color.r + light_color.g + light_color.b) / 3.0f;

		}
		//transform to screen space:
		base = projection.transform(make_vector(base,1.0f)).xyz;
		along = projection.transform(make_vector(along, 0.0f)).xyz;
		close_to_light = projection.transform(make_vector(close_to_light, 0.0f)).xyz;
		r1 = projection.transform(make_vector( r1, 0.0f )).xyz;
		r2 = projection.transform(make_vector( r2, 0.0f )).xyz;

		//make it so that base is at the 'visible' end of the cylinder.
		if (along.z < 0.0f) {
			base += along;
			along *= -1.0f;
		}
		//output cylinder:
		base.xy = to_screen(base.xy);
		along.xy = to_screen_vec(along.xy);
		close_to_light.xy = to_screen_vec(close_to_light.xy);
		r1.xy = to_screen_vec(r1.xy);
		r2.xy = to_screen_vec(r2.xy);

		//try to find some better r1/r2:
		Vector2f a1, a2;
		{
			//want a:
			//   (cos(a) * r1 + sin(a) * r2) * along == 0
			//-> cos(a) * (r1 * along) + sin(a) * (r2 * along) == 0
			//-> sin(a) / cos(a) = -(r1 * along) / (r2 * along)
			float ang = atan2f(-r1.xy * along.xy, r2.xy * along.xy);
			float ang2 = atan2f(-r1.xy * perpendicular(along.xy), r2.xy * perpendicular(along.xy));
			a1 = cosf(ang) * r1.xy + sinf(ang) * r2.xy;
			a2 = cosf(ang2) * r1.xy + sinf(ang2) * r2.xy;
		}


		Cylinder cyl;
		cyl.base = base;
		cyl.along = along;
		cyl.a1 = a1;
		cyl.a2 = a2;
		Vector4f col;
		col.xyz = make_vector< float >(pose.skeleton->bones[b].color);
		col.w = 1.0f;
		if (!color) {
			glGetFloatv(GL_CURRENT_COLOR, (float *)&col);
		}
		cyl.color = col.xyz;
		cyl.lit = lit;
		cyl.shadow = !color && !lit; //guess if this is a shadow.
		cyl.light_cap = light_cap;
		cyl.light_rim = light_rim;
		cyl.ambient = ambient;
		cyl.close_to_light = close_to_light.xy;

		scene.push_back(cyl);


		//position stack gets end of bone:
		position_stack.push_back(position_stack.back() + rotate(make_vector< float >(pose.skeleton->bones[b].direction * pose.skeleton->bones[b].length), orientation_stack.back()));

		parent_stack.push_back(b);
	}
}

void Character::finish_draw(ostream &svg_file) {
	sort(scene.begin(), scene.end());
	for (unsigned int s = 0; s < scene.size(); ++s) {
		scene[s].draw(svg_file);
	}
	svg_file << "</svg>\n";
}
