#include "Skin.hpp"

#include <Graphics/GLExtensions.hpp>
#include <Graphics/GLSLShader.hpp>
#include <Vector/QuatGL.hpp>

#include <iostream>
#include <sstream>

#include <map>

using std::cout;
using std::endl;

using std::ostringstream;

using std::map;
using std::multimap;
using std::make_pair;
using std::pair;

namespace Character {

//To hold verts in video memory:
REQUEST_GL_EXTENSION(GL_ARB_vertex_buffer_object);
//To wrangle Uniforms:
REQUEST_GL_EXTENSION(GL_ARB_shader_objects);
//To wrangle Attributes:
REQUEST_GL_EXTENSION(GL_ARB_vertex_shader);
REQUEST_GL_EXTENSION(GL_ARB_vertex_program); //vertex_shader uses these functions.

//REQUIRE_GL_EXTENSION(GL_EXT_framebuffer_object);
//REQUIRE_GL_EXTENSION(GL_ARB_texture_rectangle);
////may have to change this for OS X support:
//REQUIRE_GL_EXTENSION(GL_ARB_texture_float);

Skin::Skin() {
	skin_buffer = 0;
	skin_index_buffer = 0;
	skin_inds = 0;
	skin_verts = 0;

	shadow_buffer = 0;
	shadow_index_buffer = 0;
	shadow_inds = 0;
	shadow_verts = 0;

	skin_program.set(NULL);
	extrude_skin_program.set(NULL);
}

namespace {
	union GLMatrix {
		struct {
			Vector4f x_dir;
			Vector4f y_dir;
			Vector4f z_dir;
			Vector4f w_dir;
		};
		struct {
			float f[16];
		};
	};
	inline Vector3f mul_vec(Skin::GLMatrix const &mat, Vector3f const &vec) {
		return vec.x * mat.x_dir.xyz + vec.y * mat.y_dir.xyz + vec.z * mat.z_dir.xyz;
	}
	inline Vector3f mul(Skin::GLMatrix const &mat, Vector3f const &vec) {
		return mul_vec(mat, vec) + mat.w_dir.xyz;
	}
};

namespace {
/*
void transform_mesh(vector< GLMatrix > const &mats, Skin::Mesh const &skin, GLuint *buffer) {
	if (skin.verts.size() == 0) return;
	assert(skin.colors.size() == skin.verts.size());
	assert(skin.norms.size() == skin.verts.size());
	assert(skin.weights.size() == skin.verts.size());
	assert(skin.bones.size() == skin.verts.size());

	vector< Vector3f > transformed_verts(skin.verts.size(), make_vector(0.0f, 0.0f, 0.0f));
	vector< Vector3f > transformed_norms(skin.verts.size(), make_vector(0.0f, 0.0f, 0.0f));

	for (unsigned int i = 0; i < skin.verts.size(); ++i) {
		for (unsigned int w = 0; w < 4; ++w) {
			unsigned int bone = skin.bones[i].c[w];
			assert(bone < mats.size());
			transformed_verts[i] += mul(mats[bone], skin.verts[i]) * skin.weights[i].c[w];
			transformed_norms[i] += mul_vec(mats[bone], skin.norms[i]) * skin.weights[i].c[w];
		}
		transformed_norms[i] = normalize(transformed_norms[i]);
	}

	if (*buffer == 0) {
		glGenBuffersARB(1, buffer);
	}
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, *buffer);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float) * 9 * skin.verts.size(), NULL, GL_STREAM_DRAW_ARB);

	float *mapped = (float *)glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	assert(mapped);
	for (unsigned int i = 0; i < skin.verts.size(); ++i) {
		*mapped = skin.colors[i].c[0]; ++mapped;
		*mapped = skin.colors[i].c[1]; ++mapped;
		*mapped = skin.colors[i].c[2]; ++mapped;
		*mapped = transformed_norms[i].c[0]; ++mapped;
		*mapped = transformed_norms[i].c[1]; ++mapped;
		*mapped = transformed_norms[i].c[2]; ++mapped;
		*mapped = transformed_verts[i].c[0]; ++mapped;
		*mapped = transformed_verts[i].c[1]; ++mapped;
		*mapped = transformed_verts[i].c[2]; ++mapped;
	}

	if (glUnmapBufferARB(GL_ARRAY_BUFFER_ARB) == GL_FALSE) {
		cout << "Problem transferring vertex data." << endl;
		assert(0);
	}

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	Graphics::gl_errors("Skin:: transform_mesh");

}
*/
}

namespace {
	void multiply(Skin::GLMatrix const &a, Skin::GLMatrix const &b, Skin::GLMatrix &out) {
		//Notice that these matricies are stored in column-major order.
		for (unsigned int r = 0; r < 4; ++r) {
			for (unsigned int c = 0; c < 4; ++c) {
				out.f[r+c*4] = 0.0f;
				for (unsigned int i = 0; i < 4; ++i) {
					out.f[r+c*4] += a.f[r+i*4] * b.f[i+c*4];
				}
			}
		}
	}
}

void Skin::calculate(Pose const &pose, State const &state) {
	assert(have_ARB_vertex_buffer_object());
	assert(have_ARB_shader_objects());
	assert(have_ARB_vertex_shader());
	assert(have_ARB_vertex_program());
	bone_mats.clear();
	bone_mats.resize(pose.bone_orientations.size() + 1);
	bone_mats[0].x_dir = make_vector(1.0f, 0.0f, 0.0f, 0.0f);
	bone_mats[0].y_dir = make_vector(0.0f, 1.0f, 0.0f, 0.0f);
	bone_mats[0].z_dir = make_vector(0.0f, 0.0f, 1.0f, 0.0f);
	bone_mats[0].w_dir = make_vector(0.0f, 0.0f, 0.0f, 1.0f);

	{//calculate bone matrices:
	vector< int > parent_stack;
	vector< Quatf > orientation_stack;
	vector< Vector3f > position_stack;

	Quatf state_rot = rotation(state.orientation, make_vector(0.0f, 1.0f, 0.0f));

	parent_stack.push_back(-1);
	orientation_stack.push_back(multiply(state_rot, pose.root_orientation));
	position_stack.push_back(rotate(pose.root_position, state_rot) + state.position);

	assert(pose.skeleton);

	for (unsigned int b = 0; b < pose.bone_orientations.size(); ++b) {
		while(!parent_stack.empty() && parent_stack.back() != pose.skeleton->bones[b].parent) {
			orientation_stack.pop_back();
			position_stack.pop_back();
			parent_stack.pop_back();
		}
		assert(!parent_stack.empty());

		//glPushMatrix();
		//glRotate(pose.bone_orientations[b]);
		orientation_stack.push_back(normalize(multiply(orientation_stack.back(), pose.bone_orientations[b])));

		//this is where draw code would be...
		quat_to_gl_matrix(orientation_stack.back(), bone_mats[b+1].f);
		/*//DEBUG: actually, just identify the matrix:
		bone_mats[b+1].x_dir = make_vector(1.0f, 0.0f, 0.0f, 0.0f);
		bone_mats[b+1].y_dir = make_vector(0.0f, 1.0f, 0.0f, 0.0f);
		bone_mats[b+1].z_dir = make_vector(0.0f, 0.0f, 1.0f, 0.0f);
		//but keep position:*/
		bone_mats[b+1].w_dir.xyz = position_stack.back();
		bone_mats[b+1].w_dir.w = 1.0f;

		if (b < inv_bind_mats.size()) {
			GLMatrix temp = bone_mats[b+1];
			multiply(temp, inv_bind_mats[b], bone_mats[b+1]);
		}
		/*if (pose.skeleton->bones[b].name == "lfemur") {
			cout << pose.skeleton->bones[b].name  << "(" << b + 1 << ")" << ": " << position_stack.back() << endl;
			cout << inv_bind_mats[b].w_dir << endl;
			cout << bone_mats[b+1].x_dir << endl;
			cout << bone_mats[b+1].y_dir << endl;
			cout << bone_mats[b+1].z_dir << endl;
			cout << bone_mats[b+1].w_dir << endl;
		}*/

		//glTranslate(pose.skeleton->bones[b].direction * pose.skeleton->bones[b].length);
		position_stack.push_back(position_stack.back() + rotate(make_vector< float >(pose.skeleton->bones[b].direction * pose.skeleton->bones[b].length), orientation_stack.back()));

		parent_stack.push_back(b);
	}
	}//done calculating bone mats.

/* Later on, perhaps, it'll be back here. For now, though, we're going to do it in a
 * vertex shader.
	//transform the skin meshes:
	transform_mesh(bone_mats, skin, &skin_buffer);
	//transform_mesh(bone_mats, shadow_skin, true, &skin_shadow_buffer);
*/
}

void Skin::draw(bool do_color) {
	assert(have_ARB_vertex_buffer_object());
	assert(have_ARB_shader_objects());
	assert(have_ARB_vertex_shader());
	assert(have_ARB_vertex_program());
	if (skin_buffer == 0 || skin_index_buffer == 0 || skin_inds == 0) return;
	if (skin_program.ref == NULL) return;

	glUseProgramObjectARB(skin_program->handle);

	//load all the bone matricies into uniform memory.
	for (unsigned int l = 0; l < bone_mat_locations.size() && l < bone_mats.size(); ++l) {
		glUniformMatrix4fvARB(bone_mat_locations[l], 1, GL_FALSE, bone_mats[l].f);
	}
	
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, skin_buffer);
	glColorPointer(3, GL_FLOAT, sizeof(float) * 17, 0 + (char *)NULL);
	glNormalPointer(GL_FLOAT, sizeof(float) * 17, 3 * sizeof(float) + (char *)NULL);
	glVertexAttribPointerARB(weights_attribute, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 17, 6 * sizeof(float) + (char *)NULL);
	glVertexAttribPointerARB(bones_attribute, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 17, 10 * sizeof(float) + (char *)NULL);
	glVertexPointer(3, GL_FLOAT, sizeof(float) * 17, 14 * sizeof(float) + (char *)NULL);

	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, skin_index_buffer);

	if (do_color) {
		glEnableClientState(GL_COLOR_ARRAY);
	}
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableVertexAttribArrayARB(weights_attribute);
	glEnableVertexAttribArrayARB(bones_attribute);
	glEnableClientState(GL_VERTEX_ARRAY);

	glEnable(GL_NORMALIZE);
	glDrawElements(GL_TRIANGLES, skin_inds, GL_UNSIGNED_INT, 0 + (char *)NULL);
	glDisable(GL_NORMALIZE);

	if (do_color) {
		glDisableClientState(GL_COLOR_ARRAY);
	}
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableVertexAttribArrayARB(weights_attribute);
	glDisableVertexAttribArrayARB(bones_attribute);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	glUseProgramObjectARB(0);

	Graphics::gl_errors("Skin::draw()");
}

void Skin::draw_shadow() {
	assert(have_ARB_vertex_buffer_object());
	assert(have_ARB_shader_objects());
	assert(have_ARB_vertex_shader());
	assert(have_ARB_vertex_program());
	if (shadow_buffer == 0 || shadow_index_buffer == 0 || shadow_inds == 0) return;
	if (extrude_skin_program.ref == NULL) return;

	glUseProgramObjectARB(extrude_skin_program->handle);

	//load all the bone matricies into uniform memory.
	for (unsigned int l = 0; l < extrude_bone_mat_locations.size() && l < bone_mats.size(); ++l) {
		glUniformMatrix4fvARB(extrude_bone_mat_locations[l], 1, GL_FALSE, bone_mats[l].f);
	}
	
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, shadow_buffer);
	glNormalPointer(GL_FLOAT, sizeof(float) * 14, 0 + (char *)NULL);
	glVertexAttribPointerARB(extrude_weights_attribute, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 14, 3 * sizeof(float) + (char *)NULL);
	glVertexAttribPointerARB(extrude_bones_attribute, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 14, 7 * sizeof(float) + (char *)NULL);
	glVertexPointer(3, GL_FLOAT, sizeof(float) * 14, 11 * sizeof(float) + (char *)NULL);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, shadow_index_buffer);
	Graphics::gl_errors("binding shadow_index_buffer");

	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableVertexAttribArrayARB(extrude_weights_attribute);
	glEnableVertexAttribArrayARB(extrude_bones_attribute);
	glEnableClientState(GL_VERTEX_ARRAY);

	Graphics::gl_errors("drawelements");
	glDrawElements(GL_TRIANGLES, shadow_inds, GL_UNSIGNED_INT, 0 + (char *)NULL);

	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableVertexAttribArrayARB(extrude_weights_attribute);
	glDisableVertexAttribArrayARB(extrude_bones_attribute);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

	glUseProgramObjectARB(0);

	Graphics::gl_errors("Skin::draw_shadow()");
}

#define VERT( X ) mesh.verts.push_back( Skin::InputMesh::Vert( (X), bw, bb ) )
#define TRI( V1, V2, V3, N1, N2, N3 ) mesh.triangles.push_back( Skin::InputMesh::Triangle( make_vector< unsigned int >(mesh.verts.size() + V1, mesh.verts.size() + V2, mesh.verts.size() + V3), make_vector< unsigned int >(mesh.norms.size() + N1, mesh.norms.size() + N2, mesh.norms.size() + N3), make_vector< unsigned int >(b, b, b), make_vector< unsigned int >(0, 0, 0)))
template< int Angles, int PercentLength >
void make_cylinders(Library::Skeleton const *skeleton, Skin::InputMesh &mesh) {
	Vector2f table[Angles];
	const float len_start = 0.0f + (1.0f - PercentLength / 100.0f) * 0.5f;
	const float len_end = 1.0f - (1.0f - PercentLength / 100.0f) * 0.5f;
	for (unsigned int a = 0; a < Angles; ++a) {
		float ang = float(a) / float(Angles) * 2.0f * (float)(M_PI);
		table[a] = make_vector(cosf(ang), sinf(ang));
	}
	vector< Library::Bone > const &bones = skeleton->bones;
	for (unsigned int b = 0; b < bones.size(); ++b) {
		Vector< float, 4 > bw = make_vector(1.0f, 0.0f, 0.0f, 0.0f);
		Vector< int, 4 > bb = make_vector< int >(b,b,b,b);

		Vector3f along = normalize(make_vector< float >(bones[b].direction)); //just to be sure?
		Vector3f side = make_vector(0.0f, 0.0f, 0.0f);
		unsigned int m = 0;
		for (unsigned int i = 1; i < 2; ++i) {
			if (fabs(along.c[i]) < fabs(along.c[m])) {
				m = i;
			}
		}
		side.c[m] = 1.0f;
		side = normalize(side - along * (along * side));
		Vector3f in = cross_product(side, along);
		//generate triangle indicies:
		for (unsigned int a = 0; a < Angles; ++a) {
			//side of cylinder:
			TRI(a, Angles + a, (a + 1) % Angles,
				a, a, (a + 1) % Angles);
			TRI((a + 1) % Angles, Angles + a, Angles + (a + 1) % Angles,
				(a + 1) % Angles, a, (a + 1) % Angles);
			//caps:
			TRI(a, (a + 1) % Angles, Angles * 2,
				Angles, Angles, Angles);
			TRI(Angles + (a + 1) % Angles, Angles + a, Angles * 2 + 1,
				Angles + 1, Angles + 1, Angles + 1);
		}
		//create norms:
		//norms for cylinder sides:
		for (unsigned int a = 0; a < Angles; ++a) {
			mesh.norms.push_back(side * table[a].x + in * table[a].y);
		}
		//norms for the caps:
		mesh.norms.push_back(-along);
		mesh.norms.push_back(along);
	
		side *= bones[b].radius;
		in *= bones[b].radius;
		along *= bones[b].length;
		//create cylinder verts:
		for (unsigned int a = 0; a < Angles; ++a) {
			VERT(side * table[a].x + in * table[a].y + along * len_start);
		}
		for (unsigned int a = 0; a < Angles; ++a) {
			VERT(side * table[a].x + in * table[a].y + along * len_end);
		}
		//cap center verts:
		VERT(along * len_start);
		VERT(along * len_end);

		//color:
		mesh.colors.push_back(make_vector< float >(bones[b].color));
	}
	//single texcoord only.
	mesh.texcoords.push_back(make_vector(0.0f, 0.0f));
}
#undef TRI
#undef VERT


void Skin::set_cylinders(Library::Skeleton const *skeleton) {
	InputMesh mesh;
	InputMesh shadow_mesh;
	make_cylinders< 10, 100 >(skeleton, mesh);
	make_cylinders< 5, 98 >(skeleton, shadow_mesh);
	cout << "Setting cylinder skin meshes:" << endl;
	set_skin_mesh(mesh);
	cout << "  Skin has " << mesh.triangles.size() << " triangles." << endl;
	set_shadow_mesh(shadow_mesh);
	cout << "  Shadow has " << shadow_mesh.triangles.size() << " triangles." << endl;
	//we do the cylinders entirely in the bone-local frames.
	set_inv_bind_mats(vector< GLMatrix >());
}
#undef TRI
#undef VERT

struct VertInfo {
	unsigned int vert;
	unsigned int norm;
	unsigned int color;
};

struct VertInfoLess {
	bool operator()(VertInfo const &a, VertInfo const &b) const {
		if (a.vert == b.vert) {
			if (a.norm == b.norm) {
				return a.color < b.color;
			} else return a.norm < b.norm;
		} else return a.vert < b.vert;
	}
};

typedef map< VertInfo, unsigned int, VertInfoLess > VertMap;

void load_bone_shader(string const &filename, unsigned int num_bones, Graphics::ProgramObjectRef &program, vector< GLint > &mat_locations, GLint &bones_attrib, GLint &weights_attrib) {
	assert(have_ARB_vertex_buffer_object());
	assert(have_ARB_shader_objects());
	assert(have_ARB_vertex_shader());
	assert(have_ARB_vertex_program());
	mat_locations.clear();
	mat_locations.resize(num_bones, -1);
	ostringstream bones_define;
	bones_define << "const int BONES = " << num_bones << ";";
	{
		vector< Graphics::ShaderObjectRef > objects;
		objects.push_back(Graphics::get_shader_object(vector< string >(1, bones_define.str()), filename, GL_VERTEX_SHADER_ARB));
		assert(objects.back().ref);
		program = Graphics::get_program_object(objects);
		assert(program.ref);
	}
	//Now that the program is linked, we can grab important locations:
	for (unsigned int l = 0; l < mat_locations.size(); ++l) {
		ostringstream name;
		name << "bone_mats[" << l << "]";
		mat_locations[l] = glGetUniformLocationARB(program->handle, name.str().c_str());
	}
	bones_attrib = glGetAttribLocationARB(program->handle, "bones");
	weights_attrib = glGetAttribLocationARB(program->handle, "weights");

}

void Skin::set_skin_mesh(InputMesh const &mesh) {
	assert(have_ARB_vertex_buffer_object());
	assert(have_ARB_shader_objects());
	assert(have_ARB_vertex_shader());
	assert(have_ARB_vertex_program());
	assert(!mesh.triangles.empty());
	//First determine the output triangle indicies:
	VertMap used;

	if (skin_index_buffer == 0) {
		glGenBuffersARB(1, &skin_index_buffer);
	}
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, skin_index_buffer);
	skin_inds = mesh.triangles.size() * 3;
	glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, skin_inds * sizeof(unsigned int), NULL, GL_STATIC_DRAW_ARB);
	unsigned int *index = (unsigned int *)glMapBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	assert(index);

	//total = number of verts used.
	unsigned int total = 0;
	for (unsigned int t = 0; t < mesh.triangles.size(); ++t) {
		for (unsigned int i = 0; i < 3; ++i) {
			VertInfo cur;
			cur.vert = mesh.triangles[t].verts.c[i];
			cur.norm = mesh.triangles[t].norms.c[i];
			cur.color = mesh.triangles[t].colors.c[i];
			assert(cur.vert < mesh.verts.size());
			assert(cur.norm < mesh.norms.size());
			assert(cur.color < mesh.colors.size());
			VertMap::iterator v = used.find(cur);
			if (v == used.end()) {
				v = used.insert(make_pair(cur, total)).first;
				++total;
			}
			*index = v->second; ++index;
		}
	}

	if (glUnmapBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB) == GL_FALSE) {
		cout << "Problem transferring vertex data." << endl;
		assert(0);
	}

	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

	//Now actually create the backing vertex data store:
	if (skin_buffer == 0) {
		glGenBuffersARB(1, &skin_buffer);
	}
	//Upload vertex source data into ye olde buffer:
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, skin_buffer);
	skin_verts = total;
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float) * 17 * total, NULL, GL_STATIC_DRAW_ARB);

	float *mapped = (float *)glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	assert(mapped);
	//max_bone is index of largest bone used.
	int max_bone = 0;
	for (VertMap::iterator vert = used.begin(); vert != used.end(); ++vert) {
		float *store = mapped + vert->second * 17;
		for (unsigned int j = 0; j < 3; ++j) {
			*store = mesh.colors[vert->first.color].c[j]; ++store;
		}
		for (unsigned int j = 0; j < 3; ++j) {
			*store = mesh.norms[vert->first.norm].c[j]; ++store;
		}
		for (unsigned int j = 0; j < 4; ++j) {
			*store = mesh.verts[vert->first.vert].weights.c[j]; ++store;
		}
		for (unsigned int j = 0; j < 4; ++j) {
			assert(mesh.verts[vert->first.vert].bones.c[j] >= -1);
			*store = (float)(mesh.verts[vert->first.vert].bones.c[j] + 1); ++store;
			if (mesh.verts[vert->first.vert].bones.c[j] + 1 > max_bone) {
				max_bone = mesh.verts[vert->first.vert].bones.c[j] + 1;
			}
		}
		for (unsigned int j = 0; j < 3; ++j) {
			*store = mesh.verts[vert->first.vert].pos.c[j]; ++store;
		}
	}

	if (glUnmapBufferARB(GL_ARRAY_BUFFER_ARB) == GL_FALSE) {
		cout << "Problem transferring vertex data." << endl;
		assert(0);
	}

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	//Load up a shader with a large enough bone list:
	load_bone_shader("shaders/skin_vert.glsl", max_bone + 1, skin_program, bone_mat_locations, bones_attribute, weights_attribute);

	Graphics::gl_errors("Skin::set_skin_mesh");
}


typedef multimap< pair< unsigned int, unsigned int >, pair< unsigned int, unsigned int > > EdgeMap;

void Skin::set_shadow_mesh(InputMesh const &mesh) {
	assert(have_ARB_vertex_buffer_object());
	assert(have_ARB_shader_objects());
	assert(have_ARB_vertex_shader());
	assert(have_ARB_vertex_program());

	int max_bone = 0;

	//Create buffer for index data:
	if (shadow_index_buffer == 0) {
		glGenBuffersARB(1, &shadow_index_buffer);
	}
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, shadow_index_buffer);
	//each triangle + each edge of each triangle has a triangle hanging off it.
	shadow_inds = mesh.triangles.size() * (1 + 3) * 3;
	glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, shadow_inds * sizeof(unsigned int), NULL, GL_STATIC_DRAW_ARB);
	unsigned int *index = (unsigned int *)glMapBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	unsigned int *index_limit = index + shadow_inds;
	assert(index);

	//And buffer for backing data store:
	if (shadow_buffer == 0) {
		glGenBuffersARB(1, &shadow_buffer);
	}
	//Upload vertex source data into ye olde buffer:
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, shadow_buffer);
	unsigned int total_verts = mesh.triangles.size() * 3;
	shadow_verts = total_verts;
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float) * 14 * total_verts, NULL, GL_STATIC_DRAW_ARB);

	float *buffer = (float *)glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	float *buffer_limit = buffer + 14 * total_verts;
	assert(buffer);

	unsigned int vert_count = 0;

	//Now fill 'em both in:
	EdgeMap edges;
	for (unsigned int t = 0; t < mesh.triangles.size(); ++t) {	
		Vector< unsigned int, 3 > const &tri = mesh.triangles[t].verts;
		//make sure it's a good triangle:
		for (unsigned int i = 0; i < 3; ++i) {
			assert(tri.c[i] < mesh.verts.size());
		}
		Vector3f norm = normalize(cross_product(mesh.verts[tri.y].pos - mesh.verts[tri.x].pos, mesh.verts[tri.z].pos - mesh.verts[tri.x].pos));

		//emit inds (for this triangle):
		for (unsigned int i = 0; i < 3; ++i) {
			assert(index < index_limit);
			*index = vert_count + i; ++index;
		}
		//emit inds (for edges):
		for (unsigned int i = 0; i < 3; ++i) {
			EdgeMap::iterator f = edges.find(make_pair( tri.c[(i + 1) % 3], tri.c[i] ));
			if (f == edges.end()) {
				edges.insert( make_pair(make_pair( tri.c[i], tri.c[(i + 1) % 3]), make_pair(vert_count + i, vert_count + (i + 1) % 3 ) ) );
			} else {
				assert(index + 6 <= index_limit);
				*index = vert_count + (i + 1) % 3; ++index;
				*index = vert_count + i; ++index;
				*index = f->second.first; ++index;

				*index = f->second.second; ++index;
				*index = f->second.first; ++index;
				*index = vert_count + i; ++index;
				edges.erase(f);
			}
		}
			
		//emit verts:
		for (unsigned int i = 0; i < 3; ++i) {
			assert(buffer + 14 <= buffer_limit);
			for (unsigned int j = 0; j < 3; ++j) {
				*buffer = norm.c[j]; ++buffer;
			}
			for (unsigned int j = 0; j < 4; ++j) {
				*buffer = mesh.verts[tri.c[i]].weights.c[j]; ++buffer;
			}
			for (unsigned int j = 0; j < 4; ++j) {
				assert(mesh.verts[tri.c[i]].bones.c[j] >= -1);
				*buffer = (float)(mesh.verts[tri.c[i]].bones.c[j] + 1); ++buffer;
				if (mesh.verts[tri.c[i]].bones.c[j] + 1 > max_bone) {
					max_bone = mesh.verts[tri.c[i]].bones.c[j] + 1;
				}
			}
			for (unsigned int j = 0; j < 3; ++j) {
				assert(buffer < buffer_limit);
				*buffer = mesh.verts[tri.c[i]].pos.c[j]; ++buffer;
			}
			++vert_count;
		}
	}

	if (!edges.empty()) {
		cout << "Unmatched edges (" << edges.size() << ", in fact) when setting shadow mesh. Your mesh should be sealed." << endl;
		assert(edges.empty());
	}

	assert(index == index_limit);
	assert(buffer == buffer_limit);
	assert(vert_count == total_verts);

	if (glUnmapBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB) == GL_FALSE) {
		cout << "Problem transferring index data." << endl;
		assert(0);
	}
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

	if (glUnmapBufferARB(GL_ARRAY_BUFFER_ARB) == GL_FALSE) {
		cout << "Problem transferring index data." << endl;
		assert(0);
	}
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	//Load up a shader with a large enough bone list:
	load_bone_shader("shaders/skin_extrude_vert.glsl", max_bone + 1, extrude_skin_program, extrude_bone_mat_locations, extrude_bones_attribute, extrude_weights_attribute);
	Graphics::gl_errors("Skin::set_shadow_mesh()");
}

void Skin::set_inv_bind_mats(vector< GLMatrix > const &mats) {
	inv_bind_mats = mats;
}

/* --TODO: all-hardware, one-pass, yadda yadda.
namespace {
	inline void set_up_texture_rectangle() {
		//From Apple's PBORenderToVertexArray example:
		glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
}

void Skin::setup_for_new_skin() {
	//--------------------------------------------
	//Set up the source texture with vertex data:
	if (skin_source_texture == 0) {
		glGenTextures(1, &skin_source_texture);
	}
	glBindTexture(GL_TEXTURE_RECTANGLE_ARB, skin_source_texture);
	//set texture params:
	set_up_texture_rectangle();
	//upload vertex data into texture (interal storage: 32-bit floats):
	glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_RGB32F_ARB, skin.verts.size(), 1, 0, GL_RGB, GL_FLOAT, &(skin.verts[0]));
	glBindTexture(GL_TEXTURE_RECTANGLE_ARB, 0);

	//--------------------------------------------
	//Set up the intermediate texture:
	if (skin_intermed_texture == 0) {
		glGenTextures(1, &skin_intermed_texture);
	}
	glBindTexture(GL_TEXTURE_RECTANGLE_ARB, skin_intermed_texture);
	//set texture params:
	set_up_texture_rectangle();
	//Allocate space for transformed vertex data:
	glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_RGB32F_ARB, skin.verts.size(), 1, 0, GL_RGB, GL_FLOAT, &(skin.verts[0]));
	glBindTexture(GL_TEXTURE_RECTANGLE_ARB, 0);


	//--------------------------------------------
	//Set up the frame buffer:
	if (frame_buffer_object == 0) {
		glGenFramebuffersEXT(1, &frame_buffer_object);
	}
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frame_buffer_object);
	//bind the intermediate texture as the color component of the framebuffer:
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_RECTANGLE_ARB, skin_intermed_texture, 0);
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

	GLenum res = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
	if (res != GL_FRAMEBUFFER_COMPLETE_EXT) {
		cout << "Framebuffer isn't complete: " << res << endl;
		assert(0);
	}
	Graphics::gl_errors("Skin::setup_for_new_skin()");
}
*/

} //namespace Character
