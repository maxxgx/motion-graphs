#pragma once

#include "Bone.h"
#include "Pose.h"
#include <vector>
#include <string>
#include <tuple>

using namespace std;

class Skeleton 
{
public:
	//root bone
	string order = "TX TY TZ RX RY RZ"; //default
	string axiz_order = "XYZ"; //default
	tuple<double, double, double> position;
	tuple<double, double, double> orientation;


	Skeleton(char* asf_filename, double scale);

	void apply_pose(Pose pose);

	~Skeleton();

protected:
	//other bones
	vector<Bone> bones;

};
