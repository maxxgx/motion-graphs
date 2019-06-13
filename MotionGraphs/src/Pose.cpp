#include "../headers/pch.h"
#include "..\headers\Pose.h"

Pose::Pose(long frame)
{
	this->frame = frame;
}

vector<float> Pose::getBoneTrans(string bone)
{
	return this->transf[bone];
}

int Pose::getPoseFrame()
{
	return this->frame;
}

void Pose::addTransf(string bone, vector<float> transf)
{
	this->transf.insert(pair<string, vector<float>>(bone, transf));
}

Pose::~Pose()
{
}
