#include "WriteBvh.hpp"
#define FACTOR 110

#define DOF_ORDER "zxy"
#define CHANNEL_ORDER "Zrotation Xrotation Yrotation"


namespace Library {

Quatd frame_rot() {
	Quatd rot;
	rot.clear();
	rot = rotation(M_PI * 0.5, make_vector< double >(1,0,0));
	return rot;
}

Quatd quatd(const Quatf &f) { Quatd d; d.x=f.x; d.y=f.y; d.z=f.z; d.w=f.w; return d;}
Vector3d vecd(const Vector3f &f) { Vector3d d; d.x=f.x; d.y=f.y; d.z=f.z; return d;}

// recursive function used by writeHierarchyBvh
void write_self_and_kids(ostream &os, const Library::Skeleton &skel, int self, int num_tabs, vector< int > &order);

void writeHierarchyBvh(ostream &os, const Library::Skeleton &skel, unsigned int frames, vector< int > &order) {
	os << "HIERARCHY" << endl;
	os << "ROOT root" << endl;
	os << "{" << endl;
	os << "\tOFFSET 0 0 0" << endl;
	os << "\tCHANNELS 6 Xposition Yposition Zposition " CHANNEL_ORDER << endl;

	bool has_children = false;
	for (unsigned int b = 0; b < skel.bones.size(); ++b) {
		if (skel.bones[b].parent==-1) {
			has_children = true;
			write_self_and_kids(os, skel, b, 1, order);
		}
		cout << "parent of " << skel.bones[b].name << " is " << skel.bones[b].parent << endl;
	}
	if (! has_children ) os << "\tEnd Site\n\t{\n\t\tOFFSET 0.0 0.0 0.0\n\t}\n";
	os << "}" << endl;

	os << "MOTION" << endl;
	os << "Frames:\t" << frames << endl;
	os << "Frame Time: " << skel.timestep << endl;

	//assert(order.size()==skel.bones.size());
}

void write_self_and_kids(ostream &os, const Library::Skeleton &skel, int self, int num_tabs, vector< int > & order) {
	/*if (skel.bones[self].name.find("_phantom") != string::npos) {
		// it's a phantom joint
		bool has_children = false;
		for (unsigned int b = 0; b < skel.bones.size(); ++b) {
			if (skel.bones[b].parent==self) {
				has_children = true;
				write_self_and_kids(os, skel, b, num_tabs, order);
			}
		}
		assert(has_children);
	} else { */
		order.push_back(self);

		string n = skel.bones[self].name;
		os << string(num_tabs, '\t') << "JOINT " << n << endl;
		os << string(num_tabs, '\t') << "{" << endl;
		os	<< string(num_tabs+1, '\t') << "OFFSET ";
		// actually, to get the offset, we really need the direction & length of the parent
		Vector3d direction;
		float length;
	   	if (skel.bones[self].parent==-1) { direction = make_vector<double, 3>(0.0); length = 0; }
	   	else	   { direction = skel.bones[skel.bones[self].parent].direction; length = skel.bones[skel.bones[self].parent].length; }

		// this works to create a z-up skeleton.
		//os << 100 * length * direction.x << " " << 100 * length * direction.y << " " << 100 * length * direction.z << endl;
		
		// let's work on creating a y-up skeleton.
		//os << 100 * length * direction.x << " " << 100 * length * direction.z << " " << 100 * length * -direction.y << endl;

		// now let's work on creating a y-up skeleton facing down the +z axis.
		//os << FACTOR * length * direction.y << " " << FACTOR * length * direction.z << " " << FACTOR * length * direction.x << endl;
		direction = rotate(direction, frame_rot());
		os << FACTOR * length * direction.x << " " << FACTOR * length * direction.y << " " << FACTOR * length * direction.z << endl;
		
		os	<< string(num_tabs+1, '\t') << "CHANNELS 3 " CHANNEL_ORDER << endl;
		bool has_children = false;
		for (unsigned int b = 0; b < skel.bones.size(); ++b) {
			if (skel.bones[b].parent==self) {
				has_children = true;
				write_self_and_kids(os, skel, b, num_tabs+1, order);
			}
		}
		if (!has_children) {
			os << string(num_tabs+1, '\t') << "End Site" << endl;
			os << string(num_tabs+1, '\t') << "{" << endl;
			os << string(num_tabs+2, '\t') << "OFFSET ";
			length = skel.bones[self].length;
			direction = skel.bones[self].direction;
			direction = rotate(direction, frame_rot());
			os << FACTOR * length * direction.x << " " << FACTOR * length * direction.y << " " << FACTOR * length * direction.z << endl;
			//os << FACTOR * length * direction.y << " " << FACTOR * length * direction.z << " " << FACTOR * length * direction.x << endl;
			//os << skel.bones[self].direction.x << " " << skel.bones[self].direction.y << " " << skel.bones[self].direction.z << endl;
			os << string(num_tabs+1, '\t') << "}" << endl;
		}
		os << string(num_tabs, '\t') << "}" << endl;
//	}

}

void writeFrameBvh(ostream &os, Character::Pose &pose, vector< int > order) {
	Quatd rot = rotation( -(double)M_PI * 0.5, make_vector(1.0, 0.0, 0.0) );
	Quatd xrot;
	Quatd yrot;
	Quatd zrot;
	xrot.x = 1/sqrt(2); xrot.y = 0; xrot.z = 0; xrot.w = -1/sqrt(2);
	yrot.y = 1/sqrt(2); yrot.x = 0; yrot.z = 0; yrot.w = -1/sqrt(2);
	zrot.z = 1/sqrt(2); zrot.x = 0; zrot.y = 0; zrot.w = 1/sqrt(2);

	Vector3d root_position = vecd(pose.root_position);
	//root_position = rotate(root_position, conjugate(rot));
	// GOOD, but root doesn't match

	// old
	root_position = rotate(root_position, frame_rot());
	os  << FACTOR * root_position.x << " " << FACTOR * root_position.y << " " << FACTOR * root_position.z;
	//os << "0 0 0";

	double d[3];
	//Quatd root_orientation = multiply(quatd(pose.root_orientation), xrot);
	// rotate 180 degrees about the z axis, and -90 about the x-axis
	Quatd root_orientation = quatd(pose.root_orientation);
	root_orientation = normalize(multiply(frame_rot(), multiply(root_orientation, -frame_rot())));
	root_orientation = normalize(multiply(xrot, root_orientation));

	put_dof_rot(DOF_ORDER, root_orientation, d, 0);
	os << " " << d[0] << " " << d[1] << " " << d[2];
	//os << " 0 0 0";

	/*Character::Angles angles;
	Library::Skeleton trans;
	to_euler_angles(pose, angles, trans);*/

	//cout << "Root xyz " << d[0] << " " << d[1] << " " << d[2] << endl;
	//os << " 0 0 0";
	//cout << "Frame start: " << endl;
	for (unsigned int i = 0; i < order.size(); i++) {
		int b = order[i];
		/*os << " " << angles.angles[angles.skeleton->bones[b].frame_offset + 0] << " ";
		os << -angles.angles[angles.skeleton->bones[b].frame_offset + 1] << " ";
		os << angles.angles[angles.skeleton->bones[b].frame_offset + 2];*/

		//local, parent-relative, orientation.
		Quatd orientation = quatd(pose.bone_orientations[b]);
		orientation = normalize(multiply(frame_rot(), multiply(orientation, -frame_rot())));
		put_dof_rot(DOF_ORDER, orientation, d, 0);

		Quatd check = get_dof_rot(DOF_ORDER, d, 0);
		if (length(orientation.xyzw - check.xyzw) > 0.001 && length(-orientation.xyzw - check.xyzw) > 0.001) {
			cout << "Back quaternion conversion: " << orientation << " -> " << check << endl;
			cout << " via " << d[0] << " " << d[1] << " " << d[2] << endl;
		}
		os << " " << d[0] << " " << d[1] << " " << d[2];
		
		// GOOD - don't delete! - xyz order, plain old writing 0 1 2
		//os << " " << d[0] << " " << d[1] << " " << d[2];
	}
	os << endl;
}


/* void writeFrameBvh(ostream &os, Character::Pose &pose, vector< int > order) {
	Character::Angles angles;
	Library::Skeleton transformer;
	to_euler_angles(pose, angles, transformer);
	os << 100 * angles.angles[0] << " ";
	os << 100 * angles.angles[1] << " ";
	os << 100 * angles.angles[2] << " ";
	os << angles.angles[3] << " ";
	os << angles.angles[4] << " ";
	os << angles.angles[5] << " ";
	for (unsigned int i = 0; i < order.size(); i++) {
		int b = order[i];
		os << angles.angles[angles.skeleton->bones[b].frame_offset + 0] << " ";
		os << angles.angles[angles.skeleton->bones[b].frame_offset + 1] << " ";
		os << angles.angles[angles.skeleton->bones[b].frame_offset + 2] << " ";
	}
	os << endl;
}
*/
void writeVToBvh(unsigned int motion) {
	const Library::Motion &m = Library::motion(motion);
	string bvhfilename = m.filename.substr(0, m.filename.rfind('.', m.filename.size())) + ".BVH";

	ofstream bvhFile(bvhfilename.c_str());
	
	vector< int > order;
	writeHierarchyBvh(bvhFile, *(m.skeleton), m.frames(), order);

	for (unsigned int f = 0; f < m.frames(); f++) {
		Character::Pose pose;
		m.get_pose(f,pose);
		writeFrameBvh(bvhFile, pose, order);
	}
	bvhFile.close();
}

} // end namespace Library

