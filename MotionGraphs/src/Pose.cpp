#include "../headers/pch.h"
#include "..\headers\Pose.h"

Pose::Pose(long frame)
{
	this->frame = frame;
}

vector<double> Pose::getBoneTrans(string bone)
{
	return this->transf[bone];
}

int Pose::getPoseFrame()
{
	return this->frame;
}

void Pose::addTransf(string bone, vector<double> transf)
{
	this->transf.insert(pair<string, vector<double>>(bone, transf));
}

Pose::~Pose()
{
}
