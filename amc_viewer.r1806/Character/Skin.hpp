#ifndef CHARACTER_SKIN_HPP
#define CHARACTER_SKIN_HPP

#include "Character.hpp"

#include <Library/Skeleton.hpp>

#include <Graphics/Graphics.hpp>
#include <Graphics/GLSLShader.hpp>
#include <Vector/Vector.hpp>

#include <vector>

namespace Character {
	using std::vector;
	class Skin {
	public:
		//quick hack-y union for matrix slinging:
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
		class InputMesh {
		public:
			void clear();
			//verts & attributes:
			class Vert {
			public:
				Vert(Vector3f const &_pos, Vector< float, 4 > const &_weights, Vector< int, 4 > const &_bones) : pos(_pos), weights(_weights), bones(_bones) {
				}
				Vector3f pos;
				Vector< float, 4 > weights;
				Vector< int, 4 > bones;
			};
			vector< Vert > verts;
			vector< Vector3f > norms;
			vector< Vector3f > colors;
			vector< Vector2f > texcoords;
			//triangles as vertex inds:
			class Triangle {
			public:
				Triangle(Vector< unsigned int, 3 > const &_verts, Vector< unsigned int, 3 > const &_norms, Vector< unsigned int, 3 > const &_colors, Vector< unsigned int, 3 > const &_texcoords) : verts(_verts), norms(_norms), colors(_colors), texcoords(_texcoords) {
				}
				Vector< unsigned int, 3 > verts;
				Vector< unsigned int, 3 > norms;
				Vector< unsigned int, 3 > colors;
				Vector< unsigned int, 3 > texcoords;
			};
			vector< Triangle > triangles;
		};

		class Mesh {
		public:
			void clear();
			//verts & attributes:
			vector< Vector3f > verts;
			vector< Vector3f > norms;
			vector< Vector3f > colors;
			vector< Vector< float, 4 > > weights;
			vector< Vector< unsigned int, 4 > > bones;
			//triangles as vertex inds:
			vector< Vector< unsigned int, 3 > > triangles;
		};
		Skin();
		void calculate(Pose const &pose, State const &state);
		void draw(bool do_color = true);
		void draw_shadow();
		//build a nice default mesh & shadow mesh from the skeleton.
		void set_cylinders(Library::Skeleton const *skeleton);
		void set_skin_mesh(InputMesh const &skin);
		void set_shadow_mesh(InputMesh const &skin);
		void set_inv_bind_mats(vector< GLMatrix > const &mats);
	//private:
		//Mesh skin;
		//Mesh shadow_skin;
		GLuint skin_buffer;
		GLuint skin_index_buffer;
		unsigned int skin_inds;
		unsigned int skin_verts; //for debugging purposes.

		GLuint shadow_buffer;
		GLuint shadow_index_buffer;
		unsigned int shadow_inds;
		unsigned int shadow_verts; //for debugging purposes.

		Graphics::ProgramObjectRef skin_program;
		vector< GLint > bone_mat_locations;
		GLint bones_attribute;
		GLint weights_attribute;

		Graphics::ProgramObjectRef extrude_skin_program;
		vector< GLint > extrude_bone_mat_locations;
		GLint extrude_bones_attribute;
		GLint extrude_weights_attribute;

		//these are inputs that are composed with bone_mats.
		// (that is bone_mats = transform * inv_bind_mat)
		vector< GLMatrix > inv_bind_mats;
		//These are calculated by calculate():
		vector< GLMatrix > bone_mats;

		/*//For hardware skinning:
		GLuint frame_buffer_object;
		GLuint skin_source_texture;
		GLuint skin_intermed_texture;
		

		void setup_for_new_skin();
		*/

	};
};

#endif //CHARACTER_SKIN_HPP
