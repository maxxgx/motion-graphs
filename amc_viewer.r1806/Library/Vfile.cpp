#include "Vfile.hpp"
#include <assert.h>

void Datagroup::print() {
	if (GroupID==-1) { cout << "Datagroup not inited" << endl; return; }
	cout << "Datagroup " << GroupID << ": *" << Desc << "*" << endl;
	cout << "\tType=" << char(Type+'0') << endl;
	cout << "\tFramerate=" << FR << endl;
	cout << "\tDOFS:" << endl;
	for (unsigned int i = 0; i < DOFlabels.size(); ++i) {
		cout << "\t\t" << DOFlabels[i] << endl;
	}
}

int Datagroup::read(ifstream &v) {
	short Reclen;
	readType(v, &Reclen);
	if (Reclen==0) { 
		cout << "Found datagroups null terminator" << endl;
		return 2;
	}
	if (VDEBUG) cout << "Datagroup record length " << Reclen << endl;
	readType(v, &GroupID);
	char DL;
	readType(v, &DL);
	if (DL != 0) {
		char * buffer_desc = new char[DL];
		v.read(buffer_desc, DL);
		Desc = string(buffer_desc);
		delete [] buffer_desc;
	} else {
		cout << "Huh, no desc for datagroup record" << endl;
	}
	readType(v, &Type);
	char Width;
	readType(v, &Width);

	// because I don't trust the next generation of computers
	//	not to switch datatypes
	if (Type==1)
		assert(Width==1 && sizeof(char)==1);
	if (Type==2)
		assert(Width==1 && sizeof(char)==1);
	if (Type==3)
		assert(Width==2 && sizeof(short)==2);
	if (Type==4)
		assert(Width==4 && sizeof(int)==4);
	if (Type==5)
		assert(Width==sizeof(float));
	if (Type==6)
		assert(Width==sizeof(double));
	if (Type==7)
		assert(Width==1 && sizeof(char)==1);

	readType(v, &FR);
	cout << "Framerate is " << FR << endl;

	short NumDOFS;
	readType(v, &NumDOFS);
	cout << "Got " << int(NumDOFS) << " DOFs in datagroup" << endl;
	for (int i = 0; i < NumDOFS; ++i) {
		char len;
		readType(v, &len);
		if (VDEBUG) cout << "DOFlabel " << i << "'s length: " << int(len) << endl;
		char * buffer_DOFlabel = new char[len];
		v.read(buffer_DOFlabel, len);
		DOFlabels.push_back(string(buffer_DOFlabel));
		delete [] buffer_DOFlabel;
		if (VDEBUG) cout << "DOFlabel " << i << "'s contents: " << DOFlabels[i] << endl;
	}
	if (v.fail())
		cout << "ERROR: datagroup read, but fail bit is set" << endl;
	else
		cout << "Datagroup read successfully" << endl;

	return Reclen + 2;
}

bool Vfile::read(string filename) {
	// open the file
	ifstream v(filename.c_str());
	if (!v) {
		cout << "Couldn't open file " << filename << " for reading" << endl;
		return false;
	}

	// read the static portions
	read_ok = true;
	read_header(v);
	read_sections(v);

	// check if global bodies were found and datatype is double
	if (bodies.GroupID==-1) { cout << "==============================" << endl; read_ok = false; return read_ok; }
	assert(bodies.Type==6);

	read_dynamics(v);
	v.close();
	return read_ok;

}

void Vfile::read_header(ifstream &v) {
	char buffer[2];
	short version;
	v.read(buffer, 2);
	if (v.fail()) cout << "ERROR: header read failed" << endl;
	if (buffer[0]!='V') { cout << "ERROR: expected V, got " << buffer[0] << endl; read_ok = false; }
	if (buffer[1]!='#') { cout << "ERROR: expected #, got " << buffer[1] << endl; read_ok = false; }
	readType(v, &version);
	cout << "Got version: " << version << endl;
}

void Vfile::read_sections(ifstream &v) {
	int len;
	char buffer_name[28];
	while(1) {
		readType(v, &len);
		if (len==0) {
			cout << "Reached end of sections" << endl;
			v.seekg(28, std::ios_base::cur); // skip rest of blank header
			return;
		} else {
			cout << "Section length: " << len << endl;
			v.read(buffer_name, 28);
			cout << "Section name: " << buffer_name << endl;
			if (strcmp(buffer_name, "DATAGROUP")==0) {
				read_datagroups(v, len);
			} else {
				v.seekg(len, std::ios_base::cur);
			}
		}
	}
	return;
}

void Vfile::read_datagroups(ifstream &v, int len) {
	int section_len = 0;
	while (section_len < len) {
		Datagroup g;
		int just_read = g.read(v);
		if (just_read!=2) {
			//g.print();
			if (g.Desc=="Global Bodies") {
				cout << "Found global bodies" << endl;
				bodies = g;
			} else {
				cout << "Skipping datagroup *" << g.Desc << "*" << endl;
				cout << "Note: we do not currently support local bodies" << endl;
			}
		}
		section_len += just_read;
		if (just_read==2) // 2-byte datagroup terminator
			assert(section_len==len);
	}
}

void Vfile::read_dynamics(ifstream &v) {
	short len;
	short GroupID;
	int frame;
	int prev_frame = -1;
	while(1) {
		readType(v, &len);
		if (v.eof()) { cout << "JUST KIDDING: Actually end of v file" << endl; return; }
		if (VDEBUG) cout << "length of dynamic data record: " << len << endl;
		readType(v, &GroupID);
		if (GroupID != bodies.GroupID) {
			cout << "Ignoring data from different GroupID" << endl;
			v.seekg(len - 2, std::ios_base::cur);
		} else {
			readType(v, &frame);
			if (prev_frame != -1 && prev_frame+1 != frame) {
				cout << "Frame jump : " << prev_frame
					<< "to " << frame << endl;
			}
			prev_frame = frame;
			vector< double > d(bodies.DOFlabels.size(), 0.0);
			for (unsigned int i = 0; i < d.size(); ++i) {
				readType(v, &(d[i]));
				if (VDEBUG) cout << d[i] << '\t';
			}
			if (VDEBUG) cout << endl;
			frames.push_back(d);
		}
	}
}
