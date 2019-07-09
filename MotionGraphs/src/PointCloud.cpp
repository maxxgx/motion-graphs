#include "../headers/PointCloud.h"

PointCloud::PointCloud()
{
}

PointCloud::PointCloud(PointCloud* pc)
{
	this->points = pc->points;
}

PointCloud::PointCloud(vector<PointCloud*> vpc)
{
	for (auto v: vpc) {
		this->points.insert(this->points.end(), v->points.begin(), v->points.end());
	}
}

float PointCloud::computeDistance(PointCloud* cp)
{
	float sum = 0.0f;
	int size_a = this->points.size();
	int size_b = cp->points.size();
	if (this->points.size() == cp->points.size() && points.size() > 0) {
		for (int i=0; i < this->points.size(); i++) {
			glm::vec3 vec_diff = this->getPoint(i) - cp->getPoint(i);
			float dist = glm::dot(vec_diff, vec_diff)*100;
			sum += pow(dist, 2);
		}
		return sum;
	} else
	{
		return -1.f;
	}
}

void PointCloud::addPoint(glm::vec3 p)
{
	this->points.push_back(p);
}

void PointCloud::addPointCloud(PointCloud* pc)
{
	this->points.insert(std::begin(points), std::begin(pc->points), std::end(pc->points));
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
