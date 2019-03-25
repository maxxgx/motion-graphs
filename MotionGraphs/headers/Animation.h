#pragma once

#include "Pose.h"
#include "Skeleton.h"
#include "Bone.h"

class Animation 
{
public:
	Animation(char *amc_filename);

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