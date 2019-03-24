#include "../headers/pch.h"
#include "../headers/Bone.h"


Bone::Bone(int id, string name, double dir_x, double dir_y, double dir_z,
	double axis_x, double axis_y, double axis_z, double length, string dof, vector<pair<double, double>> limits)
{
	this->id = id;
	this->name = name;

	this->dir[0] = dir_x; this->dir[1] = dir_y; this->dir[2] = dir_z;
	this->axis[0] = axis_x; this->axis[1] = axis_y; this->axis[2] = axis_z;
	this->length = length;

	// construct dof <bool, bool, bool> for rx, ry, rz
	this->dof[0] = dof.find("rx") != string::npos; 
	this->dof[1] = dof.find("ry") != string::npos;
	this->dof[2] = dof.find("rz") != string::npos;
	this->limits = limits;
}

void Bone::draw()
{
	//Draw cube placeholder
}

void Bone::apply_pose(Pose pose)
{
	vector<double> trans = pose.getBoneTrans(this->name);
	double rxyz[3] = { 0.0, 0.0, 0.0 };

	for (int i = 0, j = 0; i < 3; i++) {
		if (this->dof[i]) {
			rxyz[i] = trans.at(j);
			j++;
		}
	}
	
}

Bone::~Bone()
{
}