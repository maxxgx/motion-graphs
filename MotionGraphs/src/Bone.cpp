#include "../headers/pch.h"
#include "../headers/Bone.h"


Bone::Bone()
{
}

Bone::Bone(int id, string name, float dir_x, float dir_y, float dir_z,
	float axis_x, float axis_y, float axis_z, float length, string dof, vector<pair<float, float>> limits, float scale)
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

	this->scale = scale;
}

void Bone::apply_pose(Pose *pose)
{
	if (pose != NULL)
	{
		vector<float> trans = pose->getBoneTrans(this->name);

		for (int i = 0, j = 0; i < 3 && j < trans.size(); i++) {
			if (this->dof[i]) {
				this->rot[i] = trans.at(j);
				j++;
			}
			else {
				this->rot[i] = 0.0f;
			}
		}
		if (!strcmp(this->name.c_str(), "lhumerus")) {
			cout << "Frame " << pose->getPoseFrame() << endl;
			//cout << "rot[0] = " << rot[0] << ", rot[1] = " << rot[1] << ", rot[2] = " << rot[2] ;
			//rot[0] = -rot[0];
			//rot[1] = -rot[1];
			//rot[2] = -rot[2];
			cout << "rot[0] = " << rot[0] << ", rot[1] = " << rot[1] << ", rot[2] = " << rot[2] << endl << endl;
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

		B = glm::translate(B, glm::vec3(dir[0]*scale, dir[1]*scale, dir[2]*scale));

		glm::mat4 ax = glm::eulerAngleX(glm::radians(axis[0]));
		glm::mat4 ay = glm::eulerAngleY(glm::radians(axis[1]));
		glm::mat4 az = glm::eulerAngleZ(glm::radians(axis[2]));
		glm::mat4 C = az * ay * ax;
		glm::mat4 Cinv = glm::inverse(C);

		glm::mat4 transformX = glm::eulerAngleX(glm::radians(rot[0]));
		glm::mat4 transformY = glm::eulerAngleY(glm::radians(rot[1]));
		glm::mat4 transformZ = glm::eulerAngleZ(glm::radians(rot[2]));
		glm::mat4 M = transformZ * transformY * transformX;

		this->TranMat = B;
		this->JointMat = B * C * M * Cinv;
	}
	else { // Other bones
		glm::mat4 parent_mat = this->parent->getJointMat();

		glm::mat4 M, C, Cinv = glm::mat4(1.f);
		//if (!strcmp(this->name.c_str(), "lhumerus") || !strcmp(this->name.c_str(), "rhumerus")
		//	|| !strcmp(this->name.c_str(), "lradius") || !strcmp(this->name.c_str(), "rradius")
		//	|| !strcmp(this->name.c_str(), "lwrist") || !strcmp(this->name.c_str(), "rwrist")
		//	|| !strcmp(this->name.c_str(), "lhand") || !strcmp(this->name.c_str(), "rhand")
		//	|| !strcmp(this->name.c_str(), "lthumb") || !strcmp(this->name.c_str(), "rthumb")
		//	|| !strcmp(this->name.c_str(), "lfingers") || !strcmp(this->name.c_str(), "rfingers")
		//	) {
		//	/// Creating the Rotation matrix R (or M?)
		//	glm::mat4 transformX = dof[0] ? glm::eulerAngleX(glm::radians(parent->rot[0])) : glm::mat4(1.f);
		//	glm::mat4 transformY = dof[1] ? glm::eulerAngleY(glm::radians(parent->rot[1])) : glm::mat4(1.f);
		//	glm::mat4 transformZ = dof[2] ? glm::eulerAngleZ(glm::radians(parent->rot[2])) : glm::mat4(1.f);
		//	//glm::mat4 M = glm::eulerAngleXYZ(rot[0], rot[1], rot[2]);
		//	M = transformX * transformY * transformZ;

		//	/// C matrix == the axis, and its inverse
		//	C = glm::eulerAngleXYZ(glm::radians(parent->axis[0]), glm::radians(parent->axis[1]), glm::radians(parent->axis[2]));
		//	Cinv = glm::inverse(C);			
		//}
		//else {
		//}

		/// Creating the Rotation matrix R (or M?)
		glm::mat4 transformX, transformY, transformZ = glm::mat4(1.f);
		transformX = dof[0] == true ? glm::eulerAngleX(glm::radians(rot[0])) : glm::mat4(1.f);
		transformY = dof[1] == true ? glm::eulerAngleY(glm::radians(rot[1])) : glm::mat4(1.f);
		transformZ = dof[2] == true ? glm::eulerAngleZ(glm::radians(rot[2])) : glm::mat4(1.f);
		M = transformZ * transformY * transformX;
		//M = glm::eulerAngleXYZ(glm::radians(rot[0]), glm::radians(rot[1]), glm::radians(rot[2]));

		/// C matrix == the axis, and its inverse
		if (!strcmp(this->name.c_str(), "rradius"))
		{ }
		glm::mat4 ax = glm::eulerAngleX(glm::radians(axis[0]));
		glm::mat4 ay = glm::eulerAngleY(glm::radians(axis[1]));
		glm::mat4 az = glm::eulerAngleZ(glm::radians(axis[2]));
		C = az * ay * ax;
		//C = glm::eulerAngleXYZ(glm::radians(axis[0]), glm::radians(axis[1]), glm::radians(axis[2]));
		Cinv = glm::inverse(C);

		/// B matrix == the translation offset from the segment parent
		float joint_offset = 0.f;
		glm::vec3 joint_parent_offset = glm::vec3(1.f);
		joint_offset = this->parent->length;
		joint_parent_offset = glm::vec3(this->parent->dir[0] * joint_offset * scale,
			this->parent->dir[1] * joint_offset * scale,
			this->parent->dir[2] * joint_offset * scale);

		glm::mat4 B_joint = glm::mat4(1.f);
		B_joint = glm::translate(parent_mat, joint_parent_offset);
		
		//this->TranMat = B_joint;
		if (!strcmp(this->name.c_str(), "lclavicle") || !strcmp(this->name.c_str(), "rclavicle")) {
			this->JointMat = B_joint;
		} else 
			this->JointMat = B_joint * C * M * Cinv;


		// Transformation matrix of the segment (bone)
		//		- finds 2 adjacent joints points
		//		- find direction and rotation matrix between the points
		glm::vec3 bone_parent_offset = glm::vec3(dir[0] * length * scale, 
													dir[1] * length * scale, 
													dir[2] * length * scale);
		glm::mat4 B = glm::mat4(1.f);
		B = glm::translate(this->JointMat, bone_parent_offset);

		this->SegMat = B;
		
		glm::vec3 p1 = glm::vec3(this->JointMat[3]);
		glm::vec3 p2 = glm::vec3(this->SegMat[3]);
		glm::vec3 diff = p1 - p2;

		glm::vec3 v = glm::vec3(0.f, 1.f, 0.f);
		
		glm::vec3 rot_ax = glm::cross(v, diff);

		float len = glm::sqrt(glm::dot(diff, diff));

		float angle = 180.f / glm::pi<float>() * glm::acos(glm::dot(v, diff) / len);

		glm::mat4 R = glm::mat4(1.f);
		R = glm::rotate(R, glm::radians(angle), rot_ax);
		
		float l = glm::dot(p2, p1);

		glm::vec3 parent_half_offset = glm::vec3(dir[0] * (length / 2.f) * scale, dir[1] * (length / 2.f)* scale, dir[2] * (length / 2.f)* scale);
		glm::mat4 T = glm::mat4(1.f);
		T = glm::translate(T, parent_half_offset);

		glm::mat4 Bseg = glm::mat4(1.f);
		Bseg = glm::translate(Bseg, p1);
		Bseg = glm::translate(Bseg, -diff / 2.f);

		glm::mat4 S = glm::mat4(1.f);
		S = glm::scale(S, glm::vec3(0.5f, length*1.5 , 0.5f));
		
		SegMat = Bseg * R * S;
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

glm::mat4 Bone::getJointMat()
{
	return this->JointMat;
}

glm::mat4 Bone::getSegMat()
{
	return this->SegMat;
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
}

string Bone::getName()
{
	return this->name;
}

Bone::~Bone()
{
}