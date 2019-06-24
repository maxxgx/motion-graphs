#include "../headers/PointCloud.h"

PointCloud::PointCloud()
{
}

float PointCloud::computeDistance(PointCloud cp)
{
	return 0.f;
}

void PointCloud::addPoint(glm::vec3 p)
{
	this->points.push_back(p);
}

glm::vec3 PointCloud::getPoint(int index)
{
	if (this->points.size() > index && index >= 0) {
		return this->points.at(index);
	}
	return glm::vec3(0.f);
}

glm::mat4 PointCloud::getPointMat(glm::vec3 p) 
{
	glm::mat4 mat = glm::mat4(1.f);
	mat = glm::translate(mat, p);
	return mat;
}

PointCloud::~PointCloud()
{
}
