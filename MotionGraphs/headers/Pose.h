#pragma once
#include <vector>
#include <string>
#include <map>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace std;

/*
* A pose contains the trasformations of the a frame
*/
class Pose
{
public:
	Pose(long frame);

	glm::vec3 getRootPos();
	glm::quat getBoneTrans(string name);

	int getPoseFrame();
	
	void addTransf(string name, vector<float> transf, bool dof_x, bool dof_y, bool dof_z);

	~Pose();

private:
	int frame;
	glm::vec3 root_pos;
	map<string, glm::quat> transf;
};