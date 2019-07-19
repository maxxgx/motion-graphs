#include "../headers/Pose.h"

Pose::Pose(long frame)
{
	this->frame = frame;
}

glm::vec3 Pose::getRootPos()
{
	return this->root_pos;
}

glm::quat Pose::getBoneTrans(string name)
{
	return this->transf[name];
}

int Pose::getPoseFrame()
{
	return this->frame;
}

map<string, glm::quat> Pose::getAllPoses()
{
	return this->transf;
}

glm::quat transf_to_quat(vector<float> tranf, bool dof_x, bool dof_y, bool dof_z) 
{
	float rot_[3] = { 0.0, 0.0, 0.0 };
	bool dof[3] = {dof_x, dof_y, dof_z};
	for (int i = 0, j = 0; i < 3 && j < tranf.size(); i++) {
		if (dof[i]) {
			rot_[i] = tranf.at(j);
			j++;
		}
		else {
			rot_[i] = 0.0f;
		}
	}
	glm::quat tq = glm::quat(glm::vec3(glm::radians(rot_[0]), glm::radians(rot_[1]), glm::radians(rot_[2]) ) );
	return tq;
}

void Pose::addTransf(string name, vector<float> transf, bool dof_x, bool dof_y, bool dof_z)
{
	if (transf.size() > 3) { // root tranf is 6 in size (pos + orientation)
		root_pos = glm::vec3(transf[0], transf[1], transf[2]);
		// swap transf with the 3 rot/axis values
		vector<float> temp(3);
		copy(transf.begin() + 3, transf.end(), temp.begin());
		transf.swap(temp);
	}
	this->transf[name] = transf_to_quat(transf, dof_x, dof_y, dof_z);
}

void Pose::addSingle(string name, glm::quat q)
{
	this->transf[name] = q;
}

Pose::~Pose()
{
}
