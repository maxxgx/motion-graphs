#pragma once

#include "Bone.h"
#include "Pose.h"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Skeleton :
	public Bone
{
public:
	//root bone
	string order = "TX TY TZ RX RY RZ"; //default
	string axiz_order = "XYZ"; //default


	Skeleton();
	Skeleton(char* asf_filename, double scale);
	
	Bone* getByName(string name);

	void apply_pose(Pose* pose);
	void draw();
	tuple<double, double, double> getPos();
	void resetAll();

	~Skeleton();

protected:
	//other bones
	vector<Bone*> bones;

};