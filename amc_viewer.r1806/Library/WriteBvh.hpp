#include "Library.hpp"
#include <Character/Character.hpp>
#include "ReadSkeleton.hpp"
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::ofstream;
using std::string;

namespace Library {

// this should be passed an "euler skeleton"
// order == the order the bones are written out in the hierarchy
void writeHierarchyBvh(ostream &os, const Library::Skeleton &skel, unsigned int frames, vector< int > & order);
void writeFrameBvh(ostream &os, unsigned int frame, Character::Pose &pose, vector< int > order);
void writeVToBvh(unsigned int motion);

void put_dof_rot(string const &dof, Quatd const &rot, double *info, int start_pos);
Quatd get_dof_rot(string const &dof, double const *info, int start_pos);
}



