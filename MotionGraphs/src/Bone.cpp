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

	this->mesh = new Cube();
}

void Bone::draw()
{
	//cout << "--- drawing bone " << name << "\n";
	//Draw cube placeholder
	glPushMatrix();
	//glRotatef(axis[0], axis[0] >= 0 ? 1 : -1, 0, 0);
	//glRotatef(axis[1], 0, axis[1] >= 0 ? 1 : -1, 0);
	//glRotatef(axis[2], 0, 0, axis[2] >= 0 ? 1 : -1);
	glRotatef(axis[0], 1, 0, 0);
	glRotatef(axis[1], 0, 1, 0);
	glRotatef(axis[2], 0, 0, 1);
	glTranslatef(dir[0] * length, dir[1] * length, dir[2] * length);
	this->mesh->draw();

	for (Bone* child : this->children) {
		child->draw();
	}

	glPopMatrix();
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

void Bone::reset()
{
	for (int i = 0; i < 3; i++) {
		this->dir[i] = copy_dir[i];
		this->axis[i] = copy_axis[i];
	}
	length = copy_length;
	mesh->setPos(0.0, 0.0, 0.0);
}

string Bone::getName()
{
	return this->name;
}

Bone::~Bone()
{
}