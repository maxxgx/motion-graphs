#include "WriteAsfAmc.hpp"

namespace Library {

void writeHeaderAmc(ostream &os, string comment) {
	os << "#!OML:ASF Written by WriteAsfAmc.cpp " << endl; //<< comment << endl;
	os << ":FULLY-SPECIFIED" << endl;
	os << ":DEGREES" << endl;
	cout << "Wrote AMC header" << endl;
}

void writeFrameAmc(ostream &os, unsigned int frame, Character::Angles &angles) {
	os << frame << endl;
	double c = 1.0;
    //if (! angles.skeleton->ang_is_deg)
	//	c = 180.0 / M_PI;

	os << "root " << angles.angles[0] << " " << angles.angles[1] << " " << angles.angles[2] << " " << c * angles.angles[3] << " " << c * angles.angles[4] << " " << c * angles.angles[5] << endl;

	// howto zero root position
	//os << "root 0 0 0 " << c * angles.angles[3] << " " << c * angles.angles[4] << " " << c * angles.angles[5] << endl;
	for (unsigned int b = 0; b < angles.skeleton->bones.size(); ++b) {
		if (angles.skeleton->bones[b].euler_axes.size()!=0)
			os << angles.skeleton->bones[b].name << " ";

		// howto zero angles
		/*for (unsigned int q = 0; q < angles.skeleton->bones[b].euler_axes.size(); q++)
			os << "0 ";
		if (angles.skeleton->bones[b].euler_axes.size() != 0)
			os << endl;*/

		if (angles.skeleton->bones[b].euler_axes.size()==3) {
			os << c * angles.angles[angles.skeleton->bones[b].frame_offset + 0] << " ";
			os << c * angles.angles[angles.skeleton->bones[b].frame_offset + 1] << " ";
			os << c * angles.angles[angles.skeleton->bones[b].frame_offset + 2] << endl;
		} else if (angles.skeleton->bones[b].euler_axes.size()==2) {
			os << c * angles.angles[angles.skeleton->bones[b].frame_offset + 0] << " ";
			assert(fabsf(c * angles.angles[angles.skeleton->bones[b].frame_offset + 1]) < .001);
			os << c * angles.angles[angles.skeleton->bones[b].frame_offset + 2] << endl;
		} else if (angles.skeleton->bones[b].euler_axes.size()==1) {
			os << c * angles.angles[angles.skeleton->bones[b].frame_offset + 0] << endl;
			assert(fabsf(c * angles.angles[angles.skeleton->bones[b].frame_offset + 1]) < .001);
			assert(fabsf(c * angles.angles[angles.skeleton->bones[b].frame_offset + 2]) < .001);
		} else {
			assert(fabsf(c * angles.angles[angles.skeleton->bones[b].frame_offset + 0]) < .001);
			assert(fabsf(c * angles.angles[angles.skeleton->bones[b].frame_offset + 1]) < .001);
			assert(fabsf(c * angles.angles[angles.skeleton->bones[b].frame_offset + 2]) < .001);
		}

		if (angles.skeleton->bones[b].dof.find_first_not_of("xyz") != std::string::npos)
			assert("Unknown dof in skeleton (translation?!) -> can't write amc frame.");
	}
}

void writeVToAMC(unsigned int motion) {
	Library::Motion &m = Library::motion_nonconst(motion);
	Library::Skeleton transformer;
	string amcfilename = m.filename.substr(0, m.filename.rfind('.', m.filename.size())) + ".AMC";

	ofstream outAMC(amcfilename.c_str());
	assert(outAMC);
	
	writeHeaderAmc(outAMC, "from a .V file");

	for (unsigned int f = 0; f < m.frames(); f++) {
		Character::Pose pose;
		Character::Angles angles;
		m.get_pose(f, pose);
		to_euler_angles(pose, angles, transformer);
		writeFrameAmc(outAMC, f, angles);
	}
	outAMC.close();
	cout << "Wrote AMC: " << amcfilename << endl;
}

void writeVSKToASF(unsigned int motion) {
	Library::Motion &m = Library::motion_nonconst(motion);
	Library::Skeleton transformer;
	get_euler_skeleton(transformer, *(m.skeleton));

	string asffilename = m.filename.substr(0, m.filename.rfind('/', m.filename.size())) + "/participant.ASF";
	ofstream outASF(asffilename.c_str());

	outASF << ":version 1.10" << endl;
	outASF << ":name VICON" << endl;
	outASF << ":units" << endl;
	outASF << "  mass 1.0" << endl;
	outASF << "  length .045" << endl;
	outASF << "  angle deg" << endl;
	outASF << ":documentation" << endl;
	outASF << "  Carnegie Mellon University Motion Capture Lab" << endl;
	outASF << "  Written by WriteAsfAmc.cpp" << endl;
	outASF << ":root" << endl;
	outASF << "  order TX TY TZ RX RY RZ" << endl;
	outASF << "  axis XYZ" << endl;
	outASF << "  position 0 0 0" << endl;
	outASF << "  orientation 0 0 0" << endl;
	outASF << ":bonedata" << endl;
	
	// write out the BONE DATA
	for (unsigned int b = 0; b < transformer.bones.size(); b++) {
		outASF << " begin" << endl;
		outASF << "   id " << b << endl;
		outASF << "   name " << transformer.bones[b].name << endl;
		outASF << "   direction "
			   << transformer.bones[b].direction.x << " "
			   << transformer.bones[b].direction.y << " "
			   << transformer.bones[b].direction.z << endl;
		outASF << "   length " << transformer.bones[b].length << endl;
		double d[3];
		put_dof_rot(transformer.bones[b].offset_order, transformer.bones[b].global_to_local, d, 0);
		outASF << "   axis " << d[0] << " " << d[1] << " " << d[2] << "   ";
		for (unsigned int i = 0; i < transformer.bones[b].offset_order.size(); ++i)
			outASF << (char)toupper(transformer.bones[b].offset_order[i]);
		outASF << endl;
		outASF << "   dof";
		if (transformer.bones[b].euler_axes.size()==3)
			outASF << " rx ry rz";
		else if (transformer.bones[b].euler_axes.size()==2)
			outASF << " rx rz";
		else if (transformer.bones[b].euler_axes.size()==1)
			outASF << " rx";

		//for (unsigned int i = 0; i < transformer.bones[b].dof.size(); ++i) {
		//	outASF << " r" << transformer.bones[b].dof[i];
		//}
		outASF << endl;
		//outASF << "   limits " << endl;
		outASF << " end" << endl;
	}




	
	// write out the HIERARCHY
	outASF << ":hierarchy" << endl;
	outASF << "  begin" << endl;

	outASF << "    root ";
	for (unsigned int b = 0; b < m.skeleton->bones.size(); b++) {
			if (m.skeleton->bones[b].parent==-1)
				outASF << m.skeleton->bones[b].name << " ";
	}
	outASF << endl;

	// loop through all bones...
	for (unsigned int b = 0; b < m.skeleton->bones.size(); ++b) {
		int id = b;

		// ... if they have any children ...
		bool foundchildren = false;
		for (unsigned int bb = 0; bb < m.skeleton->bones.size(); ++bb)
			if (m.skeleton->bones[bb].parent==id)
				foundchildren = true;
		if (! foundchildren )
			continue;

		// ... then write the children out
		outASF << "    " << m.skeleton->bones[b].name;
		for (unsigned int bb = 0; bb < m.skeleton->bones.size(); ++bb)
			if (m.skeleton->bones[bb].parent==id)
				outASF << " " << m.skeleton->bones[bb].name;
		outASF << endl;
	}

	outASF << "  end" << endl;
	cout << "Wrote ASF: " << asffilename << endl;

}

} // end namespace
