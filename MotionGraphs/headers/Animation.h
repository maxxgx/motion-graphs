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
	Animation(vector<Pose*> ps);

	void addPoses(vector<Pose*> ps);

	Pose* getPoseAt(long frame);
	Pose* getNextPose();

	vector<Pose*> getPosesInRange(unsigned long start, unsigned long end);
	vector<Pose*> getAllPoses();

	long getCurrentFrame();
	long getNumberOfFrames();
	void setFrame(long frame);
	bool isOver();
	void reset();

	~Animation();

private:
	vector<Pose*> poses; //poses[0] = NULL, frame number is consistent
	long currentFrame = 0;
};