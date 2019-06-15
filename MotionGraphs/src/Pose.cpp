#include "../headers/pch.h"
#include "..\headers\Pose.h"

Pose::Pose(long frame)
{
	this->frame = frame;
	vector<float> iv;

	vector<vector<float>> init_v(31, iv);
	this->transf = init_v;
}

vector<float> Pose::getBoneTrans(int id)
{
	return this->transf[id];
}

int Pose::getPoseFrame()
{
	return this->frame;
}

void Pose::addTransf(int id, vector<float> transf)
{
	if (this->transf.size() > id) { // modify allocated elem
		this->transf.at(id) = transf;
	}
	else { // transf size too small
		this->transf.push_back(transf);
	}
}

Pose::~Pose()
{
}
