#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cmath>

using namespace std;

class PointCloud
{
public:
	PointCloud();
	PointCloud(PointCloud* pc);
	PointCloud(vector<PointCloud*> vpc);

	/*Returns the sum of squared distance*/
	float computeDistance(PointCloud* cp);
	void addPoint(glm::vec3 pos);
	void addPointCloud(PointCloud* pc);
	glm::vec3 getPoint(int index);
	glm::mat4 getPointMat(glm::vec3 p);

	~PointCloud();

	vector<glm::vec3> points;
private:

};