#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include "Pose.h"
#include "CubeCore.h"
#include <Shader.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace std;

class Bone
{
public:

	Bone();
	Bone(int id, string name, double dir_x, double dir_y, double dir_z, 
		double axis_x, double axis_y, double axis_z, double length, string dof, vector<pair<double, double>>);

	/** Methods **/

	void apply_pose(Pose* pose);

	void addParent(Bone* parent);
	void addChild(Bone* child);
	vector<Bone*> getChildren();

	glm::mat4 getTransMat();
	glm::vec3 getPos();

	void reset();

	string getName();

	~Bone();

	/** fields **/
	Bone* parent=NULL;
	vector<Bone*> children;
	int id;
	string name = "";
	//direction
	double dir[3] = { 0.0, 0.0, 0.0 };
	//axis
	double axis[3] = { 0.0, 0.0, 0.0 };

	bool dof[3];
	vector<pair<double, double>> limits;
	double length = 0;

	CubeCore* mesh;

protected:
	//Save a copy of values for reset
	double copy_dir[3] = { 0.0, 0.0, 0.0 };
	double copy_axis[3] = { 0.0, 0.0, 0.0 };
	double copy_length = 0;

	//transformation matrix
	glm::mat4 modelMat = glm::mat4(1.0f);
};