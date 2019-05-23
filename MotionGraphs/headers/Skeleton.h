#pragma once

#include "Bone.h"
#include "Pose.h"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Scene.h"
#include <Shader.h>

using namespace std;

class Skeleton :
	public Bone
{
public:
	//root bone
	string order = "TX TY TZ RX RY RZ"; //default
	string axiz_order = "XYZ"; //default


	Skeleton();
	Skeleton(char* asf_filename, float scale);
	
	Bone* getByName(string name);

	void apply_pose(Pose* pose);
	glm::vec3 getPos();
	vector<Bone*> getAllBones();
	void resetAll();

	~Skeleton();

protected:
	float scale = 1;
	//other bones
	vector<Bone*> bones;

};