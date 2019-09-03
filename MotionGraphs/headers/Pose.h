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
	Pose(const Pose &pose);

	glm::vec3 getRootPos();
	glm::quat getBoneTrans(string name);

	map<string, glm::quat> getAllPoses();

	int getPoseFrame();
	
	void addTransf(string name, vector<float> transf, bool dof_x, bool dof_y, bool dof_z);

	void addSingle(string name, glm::quat q);

	void set_pos(glm::vec3 pos);

	~Pose();

	glm::vec3 root_pos;
private:
	int frame;
	map<string, glm::quat> transf;
};