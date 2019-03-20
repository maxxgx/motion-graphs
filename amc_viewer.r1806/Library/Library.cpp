#include "Library.hpp"

#include "ReadSkeleton.hpp"

#include <Character/pose_utils.hpp>

#include <Vector/Misc.hpp>

#include <list>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

#ifdef WINDOWS
//windows-y directory listing.
#include <io.h>
#else
//linux-specific:
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

namespace Library {

using std::list;
using std::vector;
using std::deque;
using std::string;
using std::sort;

using std::cout;

char *AnnotationNames[AnnotationCount] = {
	"LeftFootPlant",
	"RightFootPlant",
	"JumpStart",
	"JumpEnd",
	"Walk",
	"Run",
};

Vector3f AnnotationColors[AnnotationCount] = {
	{{{0.5f, 0.7f, 0.5f}}},
	{{{0.7f, 0.5f, 0.5f}}},
	{{{0.2f, 0.2f, 1.0f}}},
	{{{0.5f, 0.5f, 1.0f}}},
	{{{0.1f, 0.5f, 1.0f}}},
	{{{0.1f, 0.1f, 1.0f}}},
};

namespace {
	list< Skeleton > skeletons;
	list< Motion > motions;
	vector< set< unsigned int > > motions_per_subject;
	void unload_helper(Motion *motion) {
		for (list< Motion >::iterator m = motions.begin(); m != motions.end(); ++m) {
			if (&(*m) == motion) {
				list< Motion >::iterator n = motions.insert(m, Motion());
				n->skeleton = m->skeleton;
				n->filename = m->filename;
				n->loaded = false;
				n->subject = m->subject;
				motions.erase(m);
				break;
			}
		}
	}
}

unsigned int signature = 0;

#ifdef WINDOWS
#define SEP "\\"
#else
#define SEP "/"
#endif

void directory_recursion(string base_path) {
	static int num_subjects = 0;
	string skeleton_path = "";
	vector< string > motion_paths;
	vector< string > dir_paths;
#ifndef WINDOWS
	DIR *dir = opendir(base_path.c_str());
	if (dir == NULL) {
		cerr << "Cannot open directory '" << base_path << "'" << endl;
	} else {
		struct dirent *ent;
		while ((ent = readdir(dir))) {
			string name = string(ent->d_name);
#else
	struct _finddata_t fileinfo;
	intptr_t handle = _findfirst((base_path + "\\*").c_str(), &fileinfo);
	if (handle == -1) {
		cerr << "Cannot _findfirst on '" << base_path << "\\*'" << endl;
	} else {
		while (1) {
			string name = string(fileinfo.name);
#endif
			if (name.size() > 4 && (name.substr(name.size()-4,4)==".asf"
						|| name.substr(name.size()-4,4)==".ASF"
						|| name.substr(name.size()-4,4)==".vsk"
						|| name.substr(name.size()-4,4)==".VSK")) {
				skeleton_path = base_path + SEP + name;
			} else if (name.size() > 4 && (name.substr(name.size()-4,4)==".amc"
						|| name.substr(name.size()-4,4)==".AMC"
						|| name.substr(name.size()-4,4)==".bmc"
						|| name.substr(name.size()-2,2)==".v" 
						|| name.substr(name.size()-2,2)==".V")) {
				motion_paths.push_back(base_path + SEP + name);
			} else if (name.size() > 4 && (name.substr(name.size()-4,4)==".ann")) {
				// do nothing
			} else if (name[0]!='.') {
				dir_paths.push_back(base_path + SEP + name);
			}
#ifndef WINDOWS
		}
#else
			if (0 != _findnext(handle, &fileinfo)) break;
		}
		_findclose(handle);
#endif
	}

	sort(motion_paths.begin(), motion_paths.end());

	// if no skeleton/motions in dir, that's cool, else read them in!
	if (skeleton_path == "" || motion_paths.size()==0) {
		cerr << "Either no skeleton or motions found in path '" << base_path << "'. Continuing." << endl;
	} else {
		// if skeleton is read successfully, then read motions.
		skeletons.push_back(Skeleton());
		if (!ReadSkeleton(skeleton_path, skeletons.back())) {
			cerr << "Error reading skeleton from " << skeleton_path << "." << endl;
			skeletons.pop_back();
		} else {
			cout << "Read " << skeleton_path << " (" << skeletons.back().bones.size() << " bones)" << endl;
			for (unsigned int i = 0; i < motion_paths.size(); ++i) {
				motions.push_back(Motion());
				motions.back().skeleton = &(skeletons.back());
				motions.back().filename = motion_paths[i];
				motions.back().loaded = false;
				motions.back().subject = num_subjects;
			}
			cout << "Read " << motion_paths.size() << " motions in directory '" << base_path << "'." << endl;
			num_subjects++;
		}
	}
	// recurse on directories in current dir
	for (unsigned int i = 0; i<dir_paths.size(); i++) {
		directory_recursion(dir_paths[i]);
	}
}

void init(string base_path, bool lazy) {
	skeletons.clear();
	motions.clear();

	directory_recursion(base_path);

	if (!lazy) {
		float length = 0.0;
		unsigned int frames = 0;
		for (list< Motion >::iterator m = motions.begin(); m != motions.end(); ++m) {
			if (m->load()) {
				frames += m->frames();
				length += m->length();
			} else {
				cout << "Could not load from '" << m->filename << "'." << endl;
				list< Motion >::iterator old = m;
				++m;
				motions.erase(old);
				--m;
			}
		}
		cout << "Loaded " << length << " seconds of motion (" << frames << " frames)." << endl;
	} else {
		cout << "Lazy loading of motions enabled." << endl;
	}


	cout << "Computing signature" << endl;
	long long sig = 0;
	for (list< Motion >::iterator m = motions.begin(); m != motions.end(); ++m) {
		unsigned char * c = (unsigned char *)(&m->data[0]);
		unsigned char *end = (unsigned char *)(&m->data[m->data.size()-1]+1);
		while (c != end) {
			sig = (sig * 256) % 1610612741LL;
			sig = (sig + (long long)(*c)) % 1610612741LL;
			++c;
		}
	}
	signature = (unsigned int)(sig & 0xffffffff);
	cout << "Signature is " << signature << endl;
	return;
}

unsigned int motion_count() {
	return motions.size();
}

Motion const &motion(unsigned int index) {
	assert(index < motions.size());
	list< Motion >::const_iterator m = motions.begin();
	for (unsigned int i = 0; i < index; ++i) ++m;
	return *m;
}

Motion &motion_nonconst(unsigned int index) {
	assert(index < motions.size());
	list< Motion >::iterator m = motions.begin();
	for (unsigned int i = 0; i < index; ++i) ++m;
	return *m;
}

void Motion::get_delta(unsigned int frame_from, unsigned int frame_to, Character::StateDelta &into) const {
	assert(loaded);
	into.clear();
	assert(frame_from < smooth_root.size());
	assert(frame_to < smooth_root.size());
	into.position = rotate_by_yaw(smooth_root[frame_to].position - smooth_root[frame_from].position, -smooth_root[frame_from].orientation);
	into.orientation = smooth_root[frame_to].orientation - smooth_root[frame_from].orientation;
	//TODO: jumpping?
}

//void Motion::get_state(unsigned int frame, Character::State &into) const {
//	//ok, not doing this one for now.
//	into.clear();
//}

void Motion::get_angles(unsigned int frame, Character::Angles &into) const {
	assert(loaded);
	//simple!
	assert(skeleton);
	skeleton->build_angles(frame, data, into);
}

void Motion::get_pose(unsigned int frame, Character::Pose &into) const {
	assert(loaded);
	//simple!
	assert(skeleton);
	assert(frame < frames());
	assert((frame + 1) * skeleton->frame_size <= data.size());
	skeleton->build_pose(&(data[0]) + frame * skeleton->frame_size, into);
}

void Motion::get_local_pose(unsigned int frame, Character::Pose &into) const {
	assert(loaded);
	get_pose(frame, into);
	get_local_root(frame, into);
}

void Motion::get_local_root(unsigned int frame, Character::Pose &override) const {
	assert(loaded);
	get_local_root(frame, override.root_position, override.root_orientation);
}

void Motion::get_local_root(unsigned int frame, Vector3f &position, Quatf &orientation) const {
	assert(loaded);
	assert(frame < local_root.size());
	position = local_root[frame].position;
	orientation = local_root[frame].orientation;
}

void Motion::get_control(unsigned int frame, Character::Control &into) const {
	assert(loaded);
	assert(frame < control_data.size());
	into = control_data[frame];
}

Character::Control const &Motion::get_control(unsigned int frame) const {
	assert(loaded);
	assert(frame < control_data.size());
	return control_data[frame];
}

float Motion::get_distance_to_floor(unsigned int frame) const {
	assert(loaded);
	assert(frame < distance_to_floor.size());
	return distance_to_floor[frame];
}

int Motion::get_annotation(unsigned int frame) const {
	assert(loaded);
	assert(frame < frames());
	return annotations[frame];
}

void Motion::add_annotation(unsigned int frame, Annotation annotation) {
	assert(loaded);
	assert(frame < frames());
	annotations[frame] |= annotation;
}

void Motion::clear_annotation(unsigned int frame, Annotation annotation) {
	assert(loaded);
	assert(frame < frames());
	int a = annotation;
	annotations[frame] &= ~a;
}

bool Motion::save_annotations() const {
	string save_file = filename;
	assert(filename.size() > 3);
	if (filename.substr(filename.size()-4, 4)==".amc" || filename.substr(filename.size()-4, 4)==".AMC" || filename.substr(filename.size()-4, 4)==".bmc") {
		save_file[save_file.size()-1] = 'n';
		save_file[save_file.size()-2] = 'n';
		save_file[save_file.size()-3] = 'a';
	} else {
		save_file[save_file.size()-1] = 'a';
		save_file += "nn";
	}

	std::ofstream annFile(save_file.c_str());
	if ( ! annFile ) return false;
	for (unsigned int f = 0; f < frames(); ++f) {
		annFile << f << " " << annotations[f] << endl;
	}
	annFile.close();
	std::cout << "Saved annotation file " << save_file << "." << std::endl;
	return true;
}

bool Motion::load_annotations() {
	string load_file = filename;
	assert(filename.size() > 3);
	if (filename.substr(filename.size()-4, 4)==".amc" || filename.substr(filename.size()-4, 4)==".AMC" || filename.substr(filename.size()-4, 4)==".bmc" ) {
		load_file[load_file.size()-1] = 'n';
		load_file[load_file.size()-2] = 'n';
		load_file[load_file.size()-3] = 'a';
	} else {
		load_file[load_file.size()-1] = 'a';
		load_file += "nn";
	}

	std::ifstream annFile(load_file.c_str());
	if ( ! annFile ) {
		//cerr << "No such annotation file: " << load_file << "." << std::endl;
		return false;
	}
	unsigned int frame_num;
	for (unsigned int f = 0; f < frames(); ++f) {
		annFile >> frame_num;
		if (frame_num != f) {
			cerr << "Annotation frame mismatch in " << load_file << std::endl;
			return false;
		}
		annFile >> annotations[f];
	}
	annFile.close();
	return true;
}

bool Motion::load() {
	if (loaded) {
		cerr << "Double loading a motion." << endl;
	}
	if (!ReadAnimation(filename, *skeleton, data)) {
		cerr << "Error reading animation from " << filename << "." << endl;
		return false;
	}
	loaded = true;
	cout << "Read " << filename << " (" << frames() << " frames)" << endl;
	annotations.clear();
	annotations.resize(frames(), 0);
	load_annotations();
	calculate_control_data();
	return true;
}

void Motion::unload() {
	//Sleazy unload trick:
	unload_helper(this);
	return;
	/*
	if (!loaded) {
		cerr << "Double unloading a motion." << endl;
	}
	data.clear();
	if (data.capacity() != 0) {
		cout << "Data still using " << data.capacity() * sizeof(double) << " bytes." << endl;
		//assert(false);
	}
	control_data.clear();
	local_root.clear();
	smooth_root.clear();
	distance_to_floor.clear();
	annotations.clear();
	loaded = false;
	*/
}

unsigned int Motion::frames() const {
	assert(loaded);
	assert(skeleton);
	return data.size() / skeleton->frame_size;
}

float Motion::length() const {
	assert(loaded);
	assert(skeleton);
	return frames() * (float)skeleton->timestep;
}

void Motion::calculate_control_data() {
	local_root.clear();
	local_root.resize(frames());
	smooth_root.clear();
	smooth_root.resize(frames());
	distance_to_floor.clear();
	distance_to_floor.resize(frames());
	//calculate smooth root
	{
	for (unsigned int i = 0; i < frames(); ++i) {
		Character::Pose pose;
		get_pose(i, pose);
		//we'll project the center-of-mass onto the floor:
		Character::WorldBones wb;
		get_world_bones(pose, wb);
		assert(wb.bases.size() == pose.skeleton->bones.size());
		assert(wb.tips.size() == pose.skeleton->bones.size());
		smooth_root[i].position = make_vector(0.0f, 0.0f, 0.0f);
		float mass = 0.0f;
		for (unsigned int b = 0; b < wb.bases.size(); ++b) {
			float m = powf((float)pose.skeleton->bones[b].radius, 2.0f) * (float)M_PI * (float)pose.skeleton->bones[b].density * (float)pose.skeleton->bones[b].length;
			smooth_root[i].position += 0.5f * m * (wb.bases[b] + wb.tips[b]);
			mass += m;
		}
		if (mass == 0.0f) {
			cout << "Zero mass determining smooth root." << endl;
		} else {
			smooth_root[i].position /= mass;
		}
		smooth_root[i].position.y = 0.0f; //project.
		smooth_root[i].orientation = get_yaw_angle(pose.root_orientation);
		if (i > 0) {
			//fix up orientation to prevent sudden spins.
			while (smooth_root[i].orientation + float(M_PI) < smooth_root[i-1].orientation) {
				smooth_root[i].orientation += 2.0f * float(M_PI);
			}
			while (smooth_root[i].orientation - float(M_PI) > smooth_root[i-1].orientation) {
				smooth_root[i].orientation -= 2.0f * float(M_PI);
			}
		}
	}
	}
	//actually, um, smooth things a bit, orientation-wise.
	deque< float > buffer;
	unsigned int i = 0;
	buffer.push_back(smooth_root[0].orientation);
	while (!buffer.empty()) {
		++i;
		if (i < frames()) buffer.push_back(smooth_root[i].orientation);
		if (buffer.size() > 12 || i >= frames()) buffer.pop_front();
		if (i-6 < smooth_root.size() && !buffer.empty()) {
			float avg = 0.0f;
			for (unsigned int j = 0; j < buffer.size(); ++j) {
				avg += buffer[j];
			}
			avg /= buffer.size();
			smooth_root[i-6].orientation = avg;
		}
	}
	for (unsigned int i = 0; i < frames(); ++i) {
		Character::Pose pose;
		get_pose(i, pose);
		Quatf inv = -rotation(smooth_root[i].orientation, make_vector(0.0f, 1.0f, 0.0f));
		local_root[i].position = rotate(pose.root_position - smooth_root[i].position, inv);
		local_root[i].orientation = multiply(inv, pose.root_orientation);
		Character::WorldBones world_bones;
		get_world_bones(pose, world_bones);
		assert(world_bones.tips.size() == world_bones.bases.size());
		for (unsigned int b = 0; b < world_bones.tips.size(); ++b) {
			if (b == 0) distance_to_floor[i] = world_bones.tips[b].y;
			if (world_bones.tips[b].y < distance_to_floor[i])
				distance_to_floor[i] = world_bones.tips[b].y;
			if (world_bones.bases[b].y < distance_to_floor[i])
				distance_to_floor[i] = world_bones.bases[b].y;
		}
	}
	control_data.clear();
	control_data.resize(frames());
	float inv_ts = 1.0f / (float)skeleton->timestep;
	int jump = 0;
	for (unsigned int i = 0; i + 1 < frames(); ++i) {
		control_data[i].clear();
		Vector3f position_delta = smooth_root[i+1].position - smooth_root[i].position;
		control_data[i].desired_velocity = rotate(smooth_root[i+1].position - smooth_root[i].position, -rotation(smooth_root[i].orientation, make_vector(0.0f, 1.0f, 0.0f))) * inv_ts;
		control_data[i].desired_turning = (smooth_root[i+1].orientation - smooth_root[i].orientation) * inv_ts;
		if (get_annotation(i) & JumpStart) {
			++jump;
			if (jump > 1) cout << "Found a double-starting jump in " << filename << "." << endl;
		}
		if (get_annotation(i) & JumpEnd) {
			--jump;
			if (jump < 0) {
				cout << "Ending a non-started jump in " << filename << "." << endl;
				jump = 0;
			}
		}
		control_data[i].jump = (jump > 0);
	}
	control_data[frames() - 1].clear();
}

} //namespace Library
