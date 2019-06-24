#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

using namespace std;

class PointCloud
{
public:
	PointCloud();

	float computeDistance(PointCloud cp);
	void addPoint(glm::vec3 pos);
	glm::vec3 getPoint(int index);
	glm::mat4 getPointMat(glm::vec3 p);

	~PointCloud();

	vector<glm::vec3> points;
private:

};