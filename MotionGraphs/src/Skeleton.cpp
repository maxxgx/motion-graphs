#include "../headers/pch.h"
#include "..\headers\Skeleton.h"

Skeleton::Skeleton(char* asf_filename, double scale)
{
}

void Skeleton::apply_pose(Pose pose)
{
	for (auto& bone : this->bones) {
		bone.apply_pose(pose);
	}
}

Skeleton::~Skeleton()
{
}
