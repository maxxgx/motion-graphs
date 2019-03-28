#include "../headers/pch.h"
#include "..\headers\Skeleton.h"

Skeleton::Skeleton()
{

}

Skeleton::Skeleton(char* asf_filename, double scale)
{
	this->mesh = new Cube();
	this->name = "root";
	bool begin = false;
	bool root, bonedata, hierarchy; root = bonedata = hierarchy = false;

	//temp var for bones
	int id = 0; string name = ""; double dir[3] = { 0.0, 0.0 ,0.0 }, axis[3] = { 0.0, 0.0 ,0.0 };
	string dof = ""; vector<pair<double, double>> limits; double length = 1.0;

	string line;
	ifstream myfile(asf_filename);
	int c = 0;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//Setting current flag
			if (strContains(line, ":root")) {
				root = true;
			}
			if (strContains(line, ":bonedata")) {
				bonedata = true;
				root = hierarchy = false;
			}
			else if (strContains(line, ":hierarchy")) {
				hierarchy = true;
				root = bonedata = false;
			}

			/*	Loading data	*/
			//cout << "loading line : " << line << "\n";
			vector<string> toks = strSplit(line, ' ');
			string::size_type sz;

			//Loading root
			if (root)
			{
				/*cout << "\n---Root toks:\n";
				for (int i = 0; i < toks.size(); i++) {
					cout << "tok[" << i << "] = " << toks.at(i) << "\n";
				}*/
				if (strContains(line, "position")) {
					for (int i = 0; i < 3; i++) { this->dir[i] = stod(toks.at(i + 1)); }
				}
				else if (strContains(line, "orientation")) {
					for (int i = 0; i < 3; i++) { this->axis[i] = stod(toks.at(i + 1)); }
				}
			} // Loading bones
			else if (bonedata) {
				//cout << "---Bone toks:\n";
				//for (int i = 0; i < toks.size(); i++) {
				//	cout << "tok[" << i << "] = " << toks.at(i) << "\n";
				//} cout << "\n";
				if (strContains(line, "end")) {
					begin = false;
					this->bones.push_back(new Bone(id, name, dir[0], dir[1], dir[2], axis[0], axis[1], axis[2], length, dof, limits));
					cout << "===   added bone " << name << "\n";
				}
				if (begin) 
				{
					string varName = line;
					if (strContains(varName, "id")) {
						id = stoi(toks.at(1));
					}
					else if (strContains(varName, "name")) {
						name = toks.at(1);
					} 
					else if (strContains(varName, "direction")) {
						for (int i = 0; i < 3; i++) { dir[i] = stod(toks.at(i + 1)); }
					}
					else if (strContains(varName, "length")) {
						length = stod(toks.at(1));
					}
					else if (strContains(varName, "axis")) {
						for (int i = 0; i < 3; i++) { axis[i] = stod(toks.at(i + 1)); }
					}
					else if (strContains(varName, "dof")) {
						dof = "";
						for (int i = 1; i < toks.size(); i++) { dof += toks.at(i); }
					}
				}
				if (strContains(line, "begin")) {
					begin = true;
				}
			}// Loading hierarchy
			else if (hierarchy) {
				if (toks.size() > 1) {
					Bone* parent = this->getByName(toks.at(0));
					for (int i = 1; i < toks.size(); i++) {
						Bone* child = this->getByName(toks.at(i));
						child->addParent(parent);
						parent->addChild(child);
					}
				}
			}

			int check = root ? 1 : 0;
			check += bonedata ? 1 : 0; check += hierarchy ? 1 : 0;
			if (check > 1) {
				cerr << "Reading file error: more than one flag active, " << root << " " << bonedata << " " << hierarchy << "\n";
			}
			c++;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";

	std::cout << "\nlines = " << c << "\n";
	for (int i = 0; i < 3; i++) {
		copy_dir[i] = this->dir[i];
		copy_axis[i] = this->axis[i];
	}
	copy_length = this->length;
}

Bone* Skeleton::getByName(string name) {
	if (name.compare(this->name) == 0)
		return this;
	for (int i = 0; i < this->bones.size(); i++) {
		if (this->bones.at(i)->getName().compare(name) == 0) {
			return this->bones.at(i);
		}
	}
}

void Skeleton::draw(Scene* scene)
{
	//Draw root first
	glPushMatrix();
	glRotatef(axis[0], 1, 0, 0);
	glRotatef(axis[1], 0, 1, 0);
	glRotatef(axis[2], 0, 0, 1);
	glTranslatef(dir[0] * scale, dir[1] * scale, dir[2] * scale);
	//mesh->x = dir[0]*scale; mesh->y = dir[1]*scale; mesh->z = dir[2]*scale;

	scene->setColor(GREEN);
	this->mesh->draw();
	//DFS depth first search
	cout << "------------------------START DRAWING---------------------------\n";
	scene->setColor(RED);
	for (Bone* direct_child : this->children)
	{
		direct_child->draw();
	}
	cout << "---------------------------------------------------\n";
	glPopMatrix();
}

tuple<double, double, double> Skeleton::getPos()
{
	return tuple<double, double, double>(dir[0], dir[1], dir[2]);
}

void Skeleton::resetAll()
{
	this->reset();
	for (Bone *b : this->bones) {
		b->reset();
	}
}

void Skeleton::apply_pose(Pose* pose)
{
	if (pose == NULL) {
		cout << "--- NULL pose!" << "\n";
		return; 
	}
	// new root coords
	cout << "getting pose name " << name << "\n";
	vector<double> ts = pose->getBoneTrans(this->name);
	cout << "ts->size = " << ts.size() << "\n";
	for (int i = 0; i < ts.size(); i++) {
		if (i < 3) {
			dir[i] = ts.at(i);
		}
		else {
			axis[i - 3] = ts.at(i);
		}
	}
	for (auto& bone : this->bones) {
		bone->apply_pose(pose);
	}
}

Skeleton::~Skeleton()
{
}
