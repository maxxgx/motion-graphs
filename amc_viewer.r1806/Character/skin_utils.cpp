#include "skin_utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using std::string;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;

using std::cerr;
using std::endl;

bool Character::load(string const &filename, Library::Skeleton const *skeleton,  Skin &skin, bool shadow) {
	ifstream file(filename.c_str());
	string line;
	Skin::InputMesh mesh;
	Skin::GLMatrix id;
	id.x_dir = make_vector(1.0f, 0.0f, 0.0f, 0.0f);
	id.y_dir = make_vector(0.0f, 1.0f, 0.0f, 0.0f);
	id.z_dir = make_vector(0.0f, 0.0f, 1.0f, 0.0f);
	id.w_dir = make_vector(0.0f, 0.0f, 0.0f, 1.0f);
	vector< Skin::GLMatrix > inv_bind_mats(skeleton->bones.size(), id);
	if (!getline(file, line) || line != "joints:") {
		cerr << "Expecting line 'joints:', but got '" << line << "'" << endl;
		return false;
	}
	map< int, int > bone_map;
	//Load the bones:
	int current_bone = 0;
	bone_map.insert(make_pair(-1,-1));
	while (getline(file, line) && line != "verts:") {
		istringstream line_stream(line);
		string name;
		Skin::GLMatrix mat;
		if (!(line_stream >> name >> mat.x_dir >> mat.y_dir >> mat.z_dir >> mat.w_dir)) {
			cerr << "Expecting a bone name and then four matrix columns in '" << line << "'" << endl;
			return false;
		}
		//do a match on bones:
		if (name == "root") {
			//root actually maps to -1.
			bone_map.insert(make_pair(current_bone, -1));
		} else if (name.size() > 4 && name.substr(name.size()-4,4) == "_tip") {
			cerr << "Ignoring '" << name << "' due to _tip suffix." << endl;
			bone_map.insert(make_pair(current_bone, -1));
		} else {
			unsigned int best_match = (unsigned)-1;
			unsigned int best_len = 0;
			unsigned int best_leftover = (unsigned)-1;
			for (unsigned int b = 0; b < skeleton->bones.size(); ++b) {
				unsigned int matching = 0;
				while (matching < name.size() && matching < skeleton->bones[b].name.size() && name[matching] == skeleton->bones[b].name[matching]) {
					++matching;
				}
				unsigned int leftover = skeleton->bones[b].name.size() - matching + name.size() - matching;
				if (matching > best_len || (matching == best_len && leftover < best_leftover)) {
					best_match = b;
					best_len = matching;
					best_leftover = leftover;
				}
			}
			if (best_match >= skeleton->bones.size()) {
				cerr << "No good match for '" << name << "' in skeleton." << endl;
				bone_map.insert(make_pair(current_bone, -1));
			} else {
				if (best_len != name.size() || best_leftover != 0) {
					cerr << "Approximately matched '" << name << "' to '" << skeleton->bones[best_match].name << "' in skeleton." << endl;
				}
				bone_map.insert(make_pair(current_bone, (int)best_match));
				inv_bind_mats[best_match] = mat;
			}
		}
		++current_bone;
	}
	//Load the verts:
	while (getline(file, line) && line != "norms:") {
		Vector3f pos;
		Vector4f weights;
		Vector< int, 4 > bones;
		istringstream line_stream(line);
		if (!(line_stream >> pos >> bones >> weights)) {
			cerr << "Expecting position, bones, and weights. Got '" << line << "'" << endl;
			return false;
		}
		for (unsigned int i = 0; i < 4; ++i) {
			if (bone_map.find(bones[i]) == bone_map.end()) {
				cerr << "Bad bone index " << bones[i] << " given in '" << line << "'" << endl;
				return false;
			}
			bones[i] = bone_map[bones[i]];
		}
		mesh.verts.push_back(Skin::InputMesh::Vert( pos, weights, bones ));
	}
	//Load the normals:
	while (getline(file, line) && line != "colors:") {
		Vector3f norm;
		istringstream line_stream(line);
		if (!(line_stream >> norm)) {
			cerr << "Expecting normal. Got '" << line << "'" << endl;
			return false;
		}
		mesh.norms.push_back(norm);
	}
	//Load the colors:
	while (getline(file, line) && line != "texcoords:") {
		Vector3f color;
		istringstream line_stream(line);
		if (!(line_stream >> color)) {
			cerr << "Expecting color. Got '" << line << "'" << endl;
			return false;
		}
		mesh.colors.push_back(color);
	}
	//Load the texcoords:
	while (getline(file, line) && line != "triangles:") {
		Vector2f tex;
		istringstream line_stream(line);
		if (!(line_stream >> tex)) {
			cerr << "Expecting texcoord. Got '" << line << "'" << endl;
			return false;
		}
		mesh.texcoords.push_back(tex);
	}
	//Load the triangles:
	while (getline(file, line)) {
		Vector< unsigned int, 3 > verts, norms, colors, texcoords;
		istringstream line_stream(line);
		if (!(line_stream >> verts >> norms >> colors >> texcoords)) {
			cerr << "Expecting verts, norms, colors, texcoords. Got '" << line << "'" << endl;
			return false;
		}
		for (unsigned int i = 0; i < 3; ++i) {
			if (verts[i] >= mesh.verts.size()) {
				cerr << "Improper vert index in '" << line << "'" << endl;
				return false;
			}
			if (norms[i] >= mesh.norms.size()) {
				cerr << "Improper norm index in '" << line << "'" << endl;
				return false;
			}
			if (colors[i] >= mesh.colors.size()) {
				cerr << "Improper color index in '" << line << "'" << endl;
				return false;
			}
			if (texcoords[i] >= mesh.texcoords.size()) {
				cerr << "Improper texcoord index in '" << line << "'" << endl;
				return false;
			}
		}
		mesh.triangles.push_back(Skin::InputMesh::Triangle(verts, norms, colors, texcoords));
	}
	if (shadow) {
		cerr << "WARNING: shadow support is rather experimental!" << endl;
		skin.set_shadow_mesh(mesh);
	} else {
		skin.set_skin_mesh(mesh);
		//some of these meshes are bad for shadow meshes.
		//skin.set_shadow_mesh(mesh);
		skin.set_inv_bind_mats(inv_bind_mats);
	}
	return true;
}
