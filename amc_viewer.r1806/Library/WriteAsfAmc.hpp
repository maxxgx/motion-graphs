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

void writeHeaderAmc(ostream &os, string comment = "");
void writeFrameAmc(ostream &os, unsigned int frame, Character::Angles &angles);
void writeVToAMC(unsigned int motion);
void writeVSKToASF(unsigned int motion);

void put_dof_rot(string const &dof, Quatd const &rot, double *info, int start_pos);
}



