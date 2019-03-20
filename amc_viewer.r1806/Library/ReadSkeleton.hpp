#ifndef READSKELETON_HPP
#define READSKELETON_HPP

#include <string>
#include <vector>
#include <Character/Character.hpp>
#include "Skeleton.hpp"

using std::string;
using std::vector;

bool ReadSkeleton(string filename, Library::Skeleton &into);

bool ReadSkeletonV(string filename, Library::Skeleton &into);

// read 'amc' file format (automatically will call below on '.bmc' and '.v', though):
bool ReadAnimation(string filename, Library::Skeleton const &on, vector< double > &positions );
// read the 'bmc' binary format (somewhat faster, probably):
bool ReadAnimationBin(string filename, Library::Skeleton const &on, vector< double > &positions );
// read the '.v' file format:
bool ReadAnimationV(string filename, Library::Skeleton const &on, vector< double > &positions );


// when using .v files, call this to get Euler angles back instead of axis-angles
void to_euler_angles(Character::Pose &pose, Character::Angles &angles, Library::Skeleton &transformer);

// copies skel into transformer, but making it into an euler-angle skeleton
// pose.skeleton = &transformer;
// pose.to_angles(angles);
// angles.to_pose(pose);
void get_euler_skeleton(Library::Skeleton &transformer, const Library::Skeleton &skel);
#endif //READSKELETON_HPP
