#include "../headers/pch.h"
#include "..\headers\Pose.h"

Pose::Pose()
{
}

vector<double> Pose::getBoneTrans(string bone)
{
	return this->transf[bone];
}

int Pose::getPoseFrame()
{
	return this->frame;
}

Pose::~Pose()
{
}
