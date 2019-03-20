#include "Draw.hpp"

#include <Library/Skeleton.hpp>

#include <Graphics/Graphics.hpp>
#include <Graphics/Font.hpp>
#include <Vector/VectorGL.hpp>
#include <Vector/QuatGL.hpp>

#include <iostream>
using std::cout;
using std::endl;

namespace {
	void draw_arrow(float len) {
		float h = 0.15f / 0.45f * len; //head size.
		float s = len - h; //shaft length
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f( 0.0f,  0.0f,-0.05f);
		glVertex3f(-0.05f, 0.0f, 0.0f);
		glVertex3f( 0.05f, 0.0f, 0.0f);
		glVertex3f(-0.05f - 0.02f / 0.15f * h, 0.0f, s);
		glVertex3f( 0.05f + 0.02f / 0.15f * h, 0.0f, s);
		glVertex3f(-0.05f - 0.13f / 0.15f * h, 0.0f, s);
		glVertex3f( 0.05f + 0.13f / 0.15f * h, 0.0f, s);
		glVertex3f( 0.0f,  0.0f, s + h);
		glEnd();
	}
}

void Character::draw(Pose const &pose, State const &state, bool detail, bool color, bool select, float alpha, string bubble) {

	glPushMatrix();
	glTranslate(state.position);
	glRotatef(state.orientation * 180.0f / (float)M_PI, 0.0f, 1.0f, 0.0f);
	glTranslate(pose.root_position);
	glRotate(pose.root_orientation);

	vector< int > parent_stack;
	//vector< Quatd > orientation_stack;
	//vector< Vector3d > position_stack;
	parent_stack.push_back(-1);
	for (unsigned int b = 0; b < pose.bone_orientations.size(); ++b) {
		while(!parent_stack.empty() && parent_stack.back() != pose.skeleton->bones[b].parent) {
			glPopMatrix();
			parent_stack.pop_back();
		}
		assert(!parent_stack.empty());

		glPushMatrix();
		glRotate(pose.bone_orientations[b]);

		if (select) glPushName(b);
//----- pasted from eariler skeleton draw code -----
	//draw thick bits.
	{
		static GLUquadric *quad = NULL;
		if (quad == NULL) {
			quad = gluNewQuadric();
		}

		Vector3d t = pose.skeleton->bones[b].direction;
		Vector3d t2;
		if (t.x == t.y && t.y == t.z) {
			t2 = normalize(cross_product(t, make_vector(t.y,t.z,-t.x)));
		} else {
			t2 = normalize(cross_product(t, make_vector(t.y,t.z,t.x)));
		}
		Vector3d t3 = cross_product(t2, t);
		glPushMatrix();
		double mat[16] = {
			t2.x, t2.y, t2.z, 0,
			t3.x, t3.y, t3.z, 0,
			t.x, t.y, t.z, 0,
			0,0,0,1
		};
		glMultMatrixd(mat);
		if (color) {
			//glColor(pose.skeleton->bones[b].color * 0.8);
			glColor4f(pose.skeleton->bones[b].color.x * 0.8, pose.skeleton->bones[b].color.y * 0.8, pose.skeleton->bones[b].color.z * 0.8, alpha);
		}
		gluCylinder(quad, pose.skeleton->bones[b].radius, pose.skeleton->bones[b].radius, pose.skeleton->bones[b].length, detail?16:8, 1);
		glRotated(180,1,0,0);
		gluDisk(quad, 0, pose.skeleton->bones[b].radius, detail?16:8, 1);
		glRotated(180,1,0,0);
		glTranslated(0, 0, pose.skeleton->bones[b].length);
		gluDisk(quad, 0, pose.skeleton->bones[b].radius, detail?16:8, 1);
		glTranslated(-pose.skeleton->bones[b].radius, 0, -pose.skeleton->bones[b].length);

		if (detail) {
			if (color) {
				//glColor(pose.skeleton->bones[b].color);
				glColor4f(pose.skeleton->bones[b].color.x, pose.skeleton->bones[b].color.y, pose.skeleton->bones[b].color.z, alpha);
			}
			gluCylinder(quad, pose.skeleton->bones[b].radius * 0.05, pose.skeleton->bones[b].radius * 0.05, pose.skeleton->bones[b].length, 6, 1);
		}
		glPopMatrix();
	}

//----- end paste -----
		if (select) glPopName();


		glTranslate(pose.skeleton->bones[b].direction * pose.skeleton->bones[b].length);
		parent_stack.push_back(b);
	} // end for
	while (!parent_stack.empty()) {
		glPopMatrix();
		parent_stack.pop_back();
	}

	if (bubble != "") {
		Graphics::FontRef gentium = Graphics::get_font("gentium.txf");
		Vector2f pos = make_vector(-(float)Graphics::aspect(), 1.0f);
		const float height = 0.07f;
		float len = gentium->get_length(bubble, height);
		glPushMatrix();

		glTranslate(pose.root_position);
		glTranslatef(0.0f, 0.6f, 0.0f); // roughly above head

		glColor3f(.1f, .1f, 0.6f);
		glBegin(GL_QUADS);
			glVertex3f(0.0, 0.0, -0.001);
			glVertex3f(0.0, height, -0.001);
			glVertex3f(len, height, -0.001);
			glVertex3f(len, 0.0, -0.001);
		glEnd();
		glColor3f(1.0f, 1.0f, 1.0f);

		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		gentium->draw(bubble, make_vector<float, 2>(0.0f), height);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glPopMatrix();
	}

	Graphics::gl_errors("Character::draw");
}

void Character::draw(Control const &control, State const &state) {
	glPushMatrix();
		glTranslate(state.position);
		glRotatef(state.orientation * 180.0f / (float)M_PI, 0.0f, 1.0f, 0.0f);
		float ang = atan2(control.desired_velocity.x, control.desired_velocity.z);
		glRotatef(ang / (float)M_PI * 180.0f, 0.0f, 1.0f, 0.0f);

		glColor3f(1.0f,0.3f,1.0f);
		draw_arrow(length(control.desired_velocity));
	glPopMatrix();

}

void Character::draw(State const &state) {
	glPushMatrix();
		glTranslate(state.position + make_vector(0.0f, 0.1f, 0.0f));
		glRotatef(state.orientation * 180.0f / (float)M_PI, 0.0f, 1.0f, 0.0f);

		//glColor3f(1,1,0.3);
		draw_arrow(0.45f);
	glPopMatrix();
}

