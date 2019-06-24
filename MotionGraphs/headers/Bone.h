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
#include <Shader.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "PointCloud.h"

using namespace std;

class Bone
{
public:

	Bone();
	Bone(int id, string name, float dir_x, float dir_y, float dir_z,
		float axis_x, float axis_y, float axis_z, float length, string dof, vector<pair<float, float>> limits, float scale);

	/** Methods **/

	void apply_pose(Pose* pose);
	void updateModelMat();

	void addParent(Bone* parent);
	void addChild(Bone* child);
	vector<Bone*> getChildren();

	glm::mat4 getJointMat();
	glm::mat4 getSegMat();
	glm::vec3 getPos();
	PointCloud* getLocalPointCloud();

	void reset();

	string getName();

	~Bone();

	/** fields **/
	Bone* parent=NULL;
	vector<Bone*> children;
	int id = 0;
	string name = "";
	//direction
	float dir[3] = { 0.0, 0.0, 0.0 };
	//axis
	float axis[3] = { 0.0, 0.0, 0.0 };
	float rot[3] = { 0.0, 0.0, 0.0 };;

	bool dof[3];
	vector<pair<float, float>> limits;
	float length = 0.f;

	float scale = 1.f;
	glm::mat4 cp_planex = glm::mat4(1.f);
	glm::mat4 cp_planez = glm::mat4(1.f);

protected:
	//Save a copy of values for reset
	float copy_dir[3] = { 0.0, 0.0, 0.0 };
	float copy_axis[3] = { 0.0, 0.0, 0.0 };
	float copy_length = 0;

	//transformation matrix
	glm::mat4 JointMat = glm::mat4(1.0f);
	glm::mat4 SegMat = glm::mat4(1.f);

	// Local pointcloud for each bone
	PointCloud *local_point_cloud = new PointCloud();

private:
	void updateJointMat();
	void updateSegMat();
	void addPointsAlongOffset(glm::vec3 diff, glm::vec3 p, float samples_along_line, glm::vec3 offset);
};