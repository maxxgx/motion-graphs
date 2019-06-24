#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "Pose.h"
#include "Skeleton.h"
#include "Bone.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>

class Animation 
{
public:
	Animation(Skeleton* sk, char *amc_filename);

	Pose* getPoseAt(long frame);
	Pose* getNextPose();

	long getCurrentFrame();
	bool isOver();
	void reset();

	~Animation();

private:
	vector<Pose*> poses; //poses[0] = NULL, frame number is consistent
	long currentFrame = 0;
};