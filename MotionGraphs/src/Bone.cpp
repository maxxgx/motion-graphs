#include "../headers/pch.h"
#include "../headers/Bone.h"


Bone::Bone()
{
}

Bone::Bone(int id, string name, float dir_x, float dir_y, float dir_z,
	float axis_x, float axis_y, float axis_z, float length, string dof, vector<pair<float, float>> limits)
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

	for (int i = 0, j = 0; i < 3 && j < trans.size(); i++) {
		if (this->dof[i]) {
			this->rot[i] = trans.at(j);
			j++;
		}
		else {
			this->rot[i] = 0.0f;
		}
	}
	updateModelMat();
}

void Bone::updateModelMat()
{
	// Only the root has parent == NULL
	if (this->parent == NULL)
	{
		//Apply transformation on model matrix
		glm::mat4 B = glm::mat4(1.0f);

		B = glm::translate(B, glm::vec3(dir[0], dir[1], dir[2]));
		//M = glm::scale(M, glm::vec3(scale));

		glm::mat4 C = glm::eulerAngleXYZ(glm::radians(axis[0]), glm::radians(axis[1]), glm::radians(axis[2]));
		glm::mat4 Cinv = glm::inverse(C);

		glm::mat4 transformX = dof[0] ? glm::eulerAngleX(glm::radians(rot[0])) : glm::mat4(1.f);
		glm::mat4 transformY = dof[1] ? glm::eulerAngleY(glm::radians(rot[1])) : glm::mat4(1.f);
		glm::mat4 transformZ = dof[2] ? glm::eulerAngleZ(glm::radians(rot[2])) : glm::mat4(1.f);
		//glm::mat4 M = glm::eulerAngleXYZ(rot[0], rot[1], rot[2]);
		glm::mat4 M = transformX * transformY * transformZ;

		this->modelMat = B * C * M * Cinv;
	}
	else { // Other bones
		glm::mat4 parent_mat = this->parent->getTransMat();

		/// Creating the Rotation matrix R (or M?)
		glm::mat4 transformX = dof[0] ? glm::eulerAngleX(glm::radians(rot[0])) : glm::mat4(1.f);
		glm::mat4 transformY = dof[1] ? glm::eulerAngleY(glm::radians(rot[1])) : glm::mat4(1.f);
		glm::mat4 transformZ = dof[2] ? glm::eulerAngleZ(glm::radians(rot[2])) : glm::mat4(1.f);
		//glm::mat4 M = glm::eulerAngleXYZ(rot[0], rot[1], rot[2]);
		glm::mat4 M = transformX * transformY * transformZ;

		/// C matrix == the axis, and its inverse
		/*glm::mat4 ax = glm::eulerAngleX(glm::radians(axis[0]));
		glm::mat4 ay = glm::eulerAngleY(glm::radians(axis[1]));
		glm::mat4 az = glm::eulerAngleZ(glm::radians(axis[2]));*/
		//glm::mat4 C = az * ay * ax;
		glm::mat4 C = glm::eulerAngleXYZ(glm::radians(axis[0]), glm::radians(axis[1]), glm::radians(axis[2]));
		glm::mat4 Cinv = glm::inverse(C);

		/// B matrix == the translation offset from the segment parent
		glm::vec3 parent_offset = glm::vec3(dir[0] * length, dir[1] * length, dir[2] * length);
		glm::mat4 B = glm::mat4(1.f);
		B = glm::translate(parent_mat, parent_offset);

		this->modelMat = B * C * M * Cinv;
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
	return this->modelMat;
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