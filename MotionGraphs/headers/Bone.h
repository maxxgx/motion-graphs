#pragma once

#include "Drawable.h"
#include "Pose.h"
#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include "Cube.h"

using namespace std;

class Bone:
	public Drawable
{
public:

	Bone();
	Bone(int id, string name, double dir_x, double dir_y, double dir_z, 
		double axis_x, double axis_y, double axis_z, double length, string dof, vector<pair<double, double>>);

	/** Methods **/
	void Drawable::draw();

	void apply_pose(Pose* pose);

	void addParent(Bone* parent);

	void reset();

	string getName();

	~Bone();

protected:
	/** fields **/
	Bone* parent=NULL;
	int id;
	string name = "";
	//direction
	double dir[3] = { 0.0, 0.0, 0.0 };
	//axis
	double axis[3] = { 0.0, 0.0, 0.0 };

	bool dof[3];
	vector<pair<double, double>> limits;
	double length = 0;

	Cube* mesh;

	//Save a copy of values for reset
	double copy_dir[3] = { 0.0, 0.0, 0.0 };
	double copy_axis[3] = { 0.0, 0.0, 0.0 };
	double copy_length = 0;
};