#ifndef VFILE_HPP
#define VFILE_HPP
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#define VDEBUG 0

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

// reads any type from a filestream
template< typename T >
void readType(std::ifstream &v, T *foo) {
	v.read((char *)foo, sizeof(T));
	if (v.fail()) {
		std::cout << "ERROR: read failed" << std::endl;
	}
}

// a helper class for the main Vfile class
// - it contains bone names and DOFs in order
class Datagroup {
public:
	Datagroup() { GroupID = -1; }
	short GroupID;
	string Desc;
	char Type;
	float FR;
	vector<string> DOFlabels;
public:
	void print();
	int read(ifstream &v); // returns # of bytes read
};

// call on a v-file
class Vfile {
public:
	Datagroup bodies;
	vector< vector< double > > frames; // assume double. asssert if not.
	bool read_ok;
	bool found_datagroup;
public:
	bool read(string filename);

private:
	// reads the version number
	void read_header(ifstream &v);

	// loop through the sections
	// - find section "DATAGROUP"
	void read_sections(ifstream &v);

	// called by read_section when it sees a DATAGROUP.
	// reads all the records in the "DATAGROUP" section
	// - record "Global Bodies" contains all the skeleton dofs
	// - other records (e.g. "Local Bodies")
	void read_datagroups(ifstream &v, int len);

	// reads the dynamic data (i.e. the frame data)
	void read_dynamics(ifstream &v);
};


#endif
