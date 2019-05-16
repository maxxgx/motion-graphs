#include "../headers/pch.h"
#include "../headers/Bone.h"


Bone::Bone()
{
}

Bone::Bone(int id, string name, double dir_x, double dir_y, double dir_z,
	double axis_x, double axis_y, double axis_z, double length, string dof, vector<pair<double, double>> limits)
{
	this->id = id;
	this->name = name;

	this->dir[0] = copy_dir[0] = dir_x;
	this->dir[1] = copy_dir[1] = dir_y;
	this->dir[2] = copy_dir[2] = dir_z;

	this->axis[0] = copy_axis[0] = axis_x;
	this->axis[1] = copy_axis[1] = axis_y;
	this->axis[2] = copy_axis[2] = axis_z;

	this->length = copy_length = length;

	// construct dof <bool, bool, bool> for rx, ry, rz
	this->dof[0] = dof.find("rx") != string::npos; 
	this->dof[1] = dof.find("ry") != string::npos;
	this->dof[2] = dof.find("rz") != string::npos;
	this->limits = limits;

	this->mesh = new CubeCore();
}

void Bone::apply_pose(Pose *pose)
{
	vector<double> trans = pose->getBoneTrans(this->name);
	//double rxyz[3] = { 0.0, 0.0, 0.0 };

	for (int i = 0, j = 0; i < 3 && j < trans.size(); i++) {
		if (this->dof[i]) {
			this->axis[i] = trans.at(j);
			j++;
		}
		else {
			this->axis[i] = 0.0;
		}
	}
}

void Bone::addParent(Bone* parent)
{
	this->parent = parent;
}

void Bone::addChild(Bone* child)
{
	this->children.push_back(child);
}

vector<Bone*> Bone::getChildren()
{
	return this->children;
}

glm::mat4 Bone::getTransMat()
{
	//Apply transformation on model matrix
	glm::mat4 M = glm::mat4(1.0f);

	if (this->parent != NULL) {
		M = this->parent->modelMat;
	}

	glm::vec3 axis = glm::vec3(this->copy_axis[0], this->copy_axis[1], this->copy_axis[2]);
	glm::quat rot = glm::angleAxis((float)axis[0], axis);
	glm::quat rx,ry,rz;

	M = glm::translate(M, glm::vec3(dir[0]*this->length, dir[1]*this->length, dir[2]*this->length));
	if (dof[2] && this->copy_axis[2] != 0.0f) rz = glm::angleAxis((float)axis[2], glm::vec3(0.0f, 0.0f, this->copy_axis[2]));
	if (dof[1] && this->copy_axis[1] != 0.0f) ry = glm::angleAxis((float)axis[1], glm::vec3(0.0f, this->copy_axis[1], 0.0f));
	if (dof[0] && this->copy_axis[0] != 0.0f) rx = glm::angleAxis((float)axis[0], glm::vec3(this->copy_axis[0], 0.0f, 0.0f));
	
	M = M * rx * ry * rz;

	this->modelMat = M;

	return M;
}

glm::vec3 Bone::getPos()
{
	return glm::vec3(dir[0] * this->length, dir[1] * this->length, dir[2] * this->length);
}

void Bone::reset()
{
	for (int i = 0; i < 3; i++) {
		this->dir[i] = copy_dir[i];
		this->axis[i] = copy_axis[i];
	}
	length = copy_length;
	mesh->pos = glm::vec3(0.0f);
}

string Bone::getName()
{
	return this->name;
}

Bone::~Bone()
{
}