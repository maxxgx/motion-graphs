#pragma once

#include "Drawable.h"
#include "Pose.h"
#include <string>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

class Bone:
	public Drawable
{
public:

	/** Methods **/
	Bone(int id, string name, double dir_x, double dir_y, double dir_z, 
		double axis_x, double axis_y, double axis_z, double length, string dof, vector<pair<double, double>>);

	void Drawable::draw();

	void apply_pose(Pose pose);

	~Bone();

protected:
	/** fields **/
	int id;
	string name = "";
	//direction
	double dir[3];
	//axis
	double axis[3];

	bool dof[3];
	vector<pair<double, double>> limits;
	double length;
};