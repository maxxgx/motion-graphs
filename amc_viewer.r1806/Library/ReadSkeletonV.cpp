#include <iostream>
#include <fstream>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <sstream>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <Vector/Vector.hpp>
#include "Vfile.hpp"

#include "ReadSkeleton.hpp"
#include "Skeleton.hpp"

using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::map;
using std::set;
using std::stack;
using std::vector;
using Library::Bone;

namespace {

void unroll(vector< vector< int > > const &list, vector< int > &target, int row = 0) {
	assert(row >= 0);
	target.push_back(row);
	if (row < (signed)list.size()) {
		for (unsigned int i = 0; i < list[row].size(); ++i) {
			unroll(list, target, list[row][i]);
		}
	}
}
}

bool ReadSkeletonV(string filename, Library::Skeleton &skel) {
	// parse the .vsk and check it has a KinematicModel
	xmlDocPtr doc;
	xmlNodePtr cur;
	doc = xmlParseFile(filename.c_str());
	if (doc==NULL) {
		cout << "XML parsing of " << filename << "failed" << endl;
		return false;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur==NULL) {
		cout << filename << " is an empty xml doc" << endl;
		return false;
	}

	cout << "Root is " << cur->name << endl;
	if (strcmp((char *)cur->name,"KinematicModel")) {
		cout << "Root should be KinematicModel, but is not" << endl;
		return false;
	}

	// Get the parameters
	map<string, float> parameters; // map of parameter -> value
	xmlChar *xpath = (xmlChar*) "//Parameter";
	xmlXPathObjectPtr result;
	xmlXPathContextPtr context;
	xmlNodeSetPtr nodeset;
	xmlChar * xname = (xmlChar*) "NAME";
	xmlChar * xvalue = (xmlChar*) "VALUE";
	xmlChar * xposition = (xmlChar*) "POSITION";
	xmlChar * xaxispair = (xmlChar*) "AXIS-PAIR";
	xmlChar * xaxis = (xmlChar*) "AXIS";



	context = xmlXPathNewContext(doc);
	result = xmlXPathEvalExpression(xpath, context);
	if (result==NULL) {
		cout << "No parameters found" << endl;
		return false;
	}

	nodeset = result->nodesetval;
	for (int i = 0; i<nodeset->nodeNr; ++i) {
		string sname = string((const char *)xmlGetProp(nodeset->nodeTab[i], xname));
		string svalue = string((const char *)xmlGetProp(nodeset->nodeTab[i], xvalue));
		istringstream s(svalue);
		float fvalue;
		s >> fvalue;
		parameters[sname] = fvalue;
		parameters["-"+sname] = -1*fvalue;
	}
	xmlXPathFreeObject(result);

	// get the skeleton root
	xmlChar *xpath_s = (xmlChar*) "//Skeleton";
	result = xmlXPathEvalExpression(xpath_s, context);
	nodeset = result->nodesetval;
	if (nodeset->nodeNr != 1) {
		cout << "Expected 1 skeleton, found " << nodeset->nodeNr << endl;
		return false;
	}

	// push the top level children onto the stack
	cur = nodeset->nodeTab[0];
	stack<xmlNodePtr> s;
	stack<int> parent;
	cur = cur->xmlChildrenNode;
	s.push(cur);
	parent.push(-1);
	vector< Vector3f > bone_positions;

	// recursive-stack-thingy to traverse the hierarchy
	while(!s.empty()) {
		xmlNodePtr p = s.top();
		s.pop();
		int myparent = parent.top();
		parent.pop();
		while(p != NULL) {
			// if node is labeled "segment", create a bone
			if (xmlStrcmp(p->name, (const xmlChar *)"Segment")==0) {
				string sname = string((const char *)xmlGetProp(p, xname));

				// read the position and get it into a float vector
				string spos = string((const char *)xmlGetProp(p, xposition));
				istringstream s(spos);
				vector<string> ps(3);
				vector<float> pf(3,0.0f);
				for (unsigned int i = 0; i < 3; ++i) {
					s >> ps[i];
					if (parameters.find(ps[i])!=parameters.end())
						pf[i] = parameters[ps[i]];
					else {
						istringstream t(ps[i]);
						t >> pf[i];
					}
				}
				bone_positions.push_back(make_vector(pf[0], pf[1], pf[2]));

				
				// create a bone and set its members
				skel.bones.push_back(Bone());
				skel.bones.back().pre_parse();
				skel.bones.back().name = sname;
				skel.bones.back().parent = myparent;
				skel.bones.back().dof = "aXYZ";
				skel.bones.back().frame_offset = 6*skel.bones.size();
				skel.bones.back().axis_offset = make_vector(0.0, 0.0, 0.0);
				skel.bones.back().offset_order = "xyz";
				skel.bones.back().global_to_local.clear();
				skel.bones.back().post_parse();
				cout << p->name << " " << sname << endl;


				// find the first element child of the node - this has to be the joint
				xmlNodePtr joint = NULL;
				{
					stack<xmlNodePtr> dumb;
					dumb.push(p->xmlChildrenNode);
					while (! dumb.empty()) {
						xmlNodePtr temp = dumb.top();
						dumb.pop();
						while(temp != NULL) {
							if (temp->type==XML_ELEMENT_NODE) {
								cout << "Got element with name " << temp->name << endl;
								joint = temp;	
								break;
							} else {
								dumb.push(temp->xmlChildrenNode);
							}
							temp = temp->next;
						}
					}
				}

				// parse the joint
				if (joint==NULL) {
					cout << "Whoa! No joint found" << endl;
					assert(0);
				} if (xmlStrcmp(joint->name, (const xmlChar *)"JointFree")==0) {
					cout << "Free joint" << endl;
					Vector3d axis;
					axis.x = 1; axis.y = 0; axis.z = 0;
					skel.bones.back().euler_axes.push_back(axis);
					axis.x = 0; axis.y = 0; axis.z = -1;
					skel.bones.back().euler_axes.push_back(axis);
					axis.x = 0; axis.y = -1; axis.z = 0;
					skel.bones.back().euler_axes.push_back(axis);
				} else if (xmlStrcmp(joint->name, (const xmlChar *)"JointBall")==0) {
					cout << "Ball joint" << endl;
					Vector3d axis;
					axis.x = 1; axis.y = 0; axis.z = 0;
					skel.bones.back().euler_axes.push_back(axis);
					axis.x = 0; axis.y = 0; axis.z = -1;
					skel.bones.back().euler_axes.push_back(axis);
					axis.x = 0; axis.y = -1; axis.z = 0;
					skel.bones.back().euler_axes.push_back(axis);
				} else if (xmlStrcmp(joint->name, (const xmlChar *)"JointHardySpicer")==0) {
					cout << "Hardy Spicer joint" << endl;
					istringstream axis_stream(string((const char *)xmlGetProp(joint, xaxispair)));
					Vector3d axis1, axis2;
					if (!(axis_stream >> axis1.x >> axis1.y >> axis1.z >> axis2.x >> axis2.y >> axis2.z)) {
						cout << "Cannot read axes for joint!" << endl;
						assert(0);
					}
					axis1 = normalize(axis1);
					axis2 = normalize(axis2);
					skel.bones.back().euler_axes.push_back(axis1);
					skel.bones.back().euler_axes.push_back(axis2);
				} else if (xmlStrcmp(joint->name, (const xmlChar *)"JointHinge")==0) {
					cout << "Hinge joint" << endl;
					istringstream axis_stream(string((const char *)xmlGetProp(joint, xaxis)));
					Vector3d axis;
					if (!(axis_stream >> axis.x >> axis.y >> axis.z)) {
						cout << "Cannot read axis for joint!" << endl;
						assert(0);
					}
					axis = normalize(axis);
					skel.bones.back().euler_axes.push_back(axis);
				} else {
					cout << "Didn't find the joint, got " << joint->name << " instead" << endl;
					assert(0);
				}



			} // end if Segment
			s.push(p->xmlChildrenNode);
			parent.push(skel.bones.size()-1);
			p = p->next;
		}
	}
	
	// clean up xml
	xmlXPathFreeObject(result);
	xmlFreeDoc(doc);

	// if a child has siblings, introduce a unique virtual parent for each one
	unsigned int orig_bone_size = skel.bones.size();
	for (unsigned int i = 0; i < orig_bone_size; ++i) {
		set<int> has_parent_i;
		has_parent_i.clear();
		for (unsigned int j = 0; j < orig_bone_size; ++j)
			if ((unsigned)skel.bones[j].parent==i)
				has_parent_i.insert(j);

		if (has_parent_i.size() == 0) {
			skel.bones[i].direction = skel.bones[skel.bones[i].parent].direction;
			skel.bones[i].length = skel.bones[skel.bones[i].parent].length / 3;
			skel.bones[i].radius = skel.bones[i].length / 1.0;
		} else if (has_parent_i.size() == 1) {
			skel.bones[i].direction = normalize(bone_positions[*(has_parent_i.begin())]);
			skel.bones[i].length = length(bone_positions[*(has_parent_i.begin())]) / 1000.0;
			skel.bones[i].radius = skel.bones[i].length / 10.0;
		} else {
			set<int>::iterator iter;
			for (iter = has_parent_i.begin(); iter!=has_parent_i.end(); ++iter) {
				skel.bones.push_back(Bone());
				skel.bones.back().pre_parse();
				skel.bones.back().name = skel.bones[*iter].name + "_phantom";
				skel.bones.back().direction = normalize(bone_positions[*iter]);
				skel.bones.back().length = length(bone_positions[*iter]) / 1000.0; // millimeters to meters
				skel.bones.back().radius = skel.bones.back().length / 10.0;
				/*
				skel.bones.back().dof = "";
				skel.bones.back().frame_offset = 6*(skel.bones.size()-1);
				*/
				//Global, so duplicate parent (this works nicely as long as we IGNORE rotations!)
				skel.bones.back().dof = skel.bones[i].dof;
				skel.bones.back().frame_offset = skel.bones[i].frame_offset;
				skel.bones.back().axis_offset = make_vector(0.0, 0.0, 0.0);
				skel.bones.back().offset_order = "xyz";
				skel.bones.back().global_to_local.clear();
				skel.bones.back().parent = i;
				skel.bones.back().post_parse();

				skel.bones[*iter].parent = skel.bones.size()-1;
				bone_positions.push_back(bone_positions[*iter]);
				bone_positions[*iter] = make_vector(0.0f, 0.0f, 0.0f);
			}
			skel.bones[i].length = 0;
			skel.bones[i].radius = 0 / 10.0;
			skel.bones[i].direction = make_vector(1.0f, 0.0f, 0.0f);
		}
	} // end for

	// set the first bone of the skeleton to have 0 DOFs
	// this frame data for it will still be copied over into the first 6 slots,
	// but it will now be read by the root.
	//skel.bones[0].dof=""; //DEBUG: see if this is a problem.

	skel.order = "aXYZ";
	skel.position = make_vector(0.0f, 0.0f, 0.0f);
	skel.offset_order = "xyz"; // unnecessary
	//skel.axis_offset = make_vector(-90.0, 0.0, 0.0);
	skel.axis_offset = make_vector(0.0, 0.0, 0.0);
	skel.timestep = 1.0 / 120.0; // Not yet supported (should be part of motion, not skel)
	skel.ang_is_deg = false;
	skel.rot_is_glob = true; // Not yet not supported (should be part of motion, not skel)
	skel.z_is_up = true; // TODO
	skel.frame_size = orig_bone_size * 6 + 6;

	// clean up the hierarchy
	cout << "Hierarchy: " << endl;
	for (unsigned int i = 0; i < skel.bones.size(); ++i)
		cout << i << " " << skel.bones[i].name << " parent " << skel.bones[i].parent << endl;

	vector<vector<int > > kids_of_i(skel.bones.size()+1);
	for (unsigned int j = 0; j < skel.bones.size(); ++j) {
		kids_of_i[skel.bones[j].parent+1].push_back(j+1);
	}
	//DEBUG:
	//for (unsigned int i = 0; i < kids_of_i.size(); ++i) {
	//	cout << (signed)(i) - 1 << " : ";
	//	for (unsigned int j = 0; j < kids_of_i[i].size(); ++j) {
	//		cout << ' ' << kids_of_i[i][j] - 1;
	//	}
	//	cout << endl;
	//}
			
	vector< int > unrolled;
	unroll(kids_of_i, unrolled);
	assert(unrolled.size() == skel.bones.size()+1);

	vector< int > unrolled_inv(unrolled.size());
	for (unsigned int i = 0; i < unrolled.size(); ++i) {
		unrolled_inv[unrolled[i]] = i;
	}
	//DEBUG:
	//for (unsigned int i = 0; i < unrolled.size(); ++i) {
	//	cout << i - 1 << " -> " << unrolled_inv[i] - 1 << endl;
	//}

	vector< Bone > bones_temp(skel.bones.size());
	for (unsigned int i = 1; i < unrolled.size(); ++i) {
		bones_temp[i-1] = skel.bones[unrolled[i]-1];
		bones_temp[i-1].parent = unrolled_inv[skel.bones[unrolled[i]-1].parent+1]-1;
	}
	skel.bones = bones_temp;

	cout << "Hierarchy (after re-ordering): " << endl;
	for (unsigned int i = 0; i < skel.bones.size(); ++i)
		cout << i << " " << skel.bones[i] << endl;
	
	return true;
}

bool ReadAnimationV(string filename, Library::Skeleton const &skel, vector< double > &positions ) {
	cout << "Reading file " << filename << endl;
	
	// read the v file
	Vfile v;
	bool success = v.read(filename);
	if (!success) return false;

	// resize the positions array to accomodate the frame data
	positions.resize(v.frames.size() * skel.frame_size, 0);
	
	// grab just the name of each bone, and put it in a map with its position
	map<string, int> DOFlabelloc;
	for (int i = (int)v.bodies.DOFlabels.size() - 1; i>=0; i--) { // get earliest loc
		string temp = v.bodies.DOFlabels[i];
		int col = temp.find(':', 0);
		string bone = temp.substr(col+1, temp.size() - (col+1) - 6);
		if (VDEBUG) cout << "Got bone *" << bone << "*" << endl;
		DOFlabelloc[bone] = i;
	}

	// move the Vfile data into the positions array
	// ASSUMPTION: 6 degrees of freedom, first 3 are angles, second 3 translations
	for (unsigned int f = 0; f < v.frames.size(); ++f) {
		
		// transfer the pelvis's angles into the root's slots (the first 6)
		int rootjoint_loc = DOFlabelloc[skel.bones[0].name];
		for (unsigned int j = 0; j < 3; ++j) {
			positions[f*skel.frame_size + j] = v.frames[f][rootjoint_loc+j];
		}
		// transfer position data (last 3 slots) and convert from millimeters to meters
		for (unsigned int j = 3; j < 6; ++j) {
			positions[f*skel.frame_size + j] = v.frames[f][rootjoint_loc+j] / 1000;
		}

		// and all the rest of the bones (including bone[0])
		for (unsigned int i = 0; i < skel.bones.size(); ++i) {
			string s = skel.bones[i].name;
			if (DOFlabelloc.find(s)==DOFlabelloc.end()) {
				if (f==0) cout << "Vfile / skeleton mismatch: " << s << endl;
			} else {
				int loc = DOFlabelloc[s];
				// transfer angle data (first 3 slots)
				for (unsigned int j = 0; j < 3; ++j) {
					assert(f*skel.frame_size+skel.bones[i].frame_offset+j < positions.size());
					positions[f*skel.frame_size + skel.bones[i].frame_offset+j] = v.frames[f][loc+j];
				}
				// transfer position data (last 3 slots) and convert from millimeters to meters
				for (unsigned int j = 3; j < 6; ++j) {
					positions[f*skel.frame_size + skel.bones[i].frame_offset+j] = v.frames[f][loc+j] / 1000;
				}
			}
		}
	}

	// actually, we should zero out the pelvis and create a root joint instead

	return true;
}

void get_euler_skeleton(Library::Skeleton &transformer, const Library::Skeleton &skel) {
	transformer.bones = skel.bones;
	transformer.position = skel.position;
	transformer.offset_order = skel.offset_order;
	transformer.axis_offset = skel.axis_offset;
	transformer.timestep = skel.timestep;
	transformer.ang_is_deg = skel.ang_is_deg;
	transformer.rot_is_glob = false;
	transformer.z_is_up = false; // UNDO
	transformer.frame_size = skel.frame_size;
	transformer.filename = "modification_of_" + skel.filename;
	transformer.order = "XYZxyz";

	for (unsigned int b = 0; b < transformer.bones.size(); ++b) {
		transformer.bones[b].frame_offset = 3*b + 6;
		transformer.bones[b].dof = "xyz";
		// use euler angle axes from .vsk

		if (transformer.bones[b].euler_axes.size()==0) {
			//transformer.bones[b].dof = ""; // would mess up the frame size
		} else if (transformer.bones[b].euler_axes.size()==1) {
			Vector3d x = make_vector(1.0, 0.0, 0.0);
			Vector3d y = make_vector(0.0, 1.0, 0.0);

			// rotate x to axis1 about cross
			Vector3d axis1 = transformer.bones[b].euler_axes[0];
			Vector3d cross = cross_product(x, axis1);
			float costheta = axis1 * x;
			float sintheta = length(cross);
			if (sintheta==0)
					cross = y;
			else
				cross = normalize(cross);
			transformer.bones[b].global_to_local = rotation(atan2(sintheta, costheta), cross);
			assert(length(rotate(x, transformer.bones[b].global_to_local) - axis1) < 10e-5);
			//cout << "Global to local after first axis computation: " << transformer.bones[b].global_to_local << endl;
		} else if (transformer.bones[b].euler_axes.size()==2 || transformer.bones[b].euler_axes.size()==3) {
			// "3" is code for "free joint, no idea"
			// so we need to fill in with reasonable stuff,
			// where euler_axes[3] would be the direction into the bone
			if (transformer.bones[b].euler_axes.size()==3) {
				int child = -1;
				for (unsigned int bchild = 0; bchild < transformer.bones.size(); bchild++)
					if (transformer.bones[bchild].parent==(int)b)
						child = bchild;
				if (child != -1) {
					Vector3d axis_down_bone = -normalize(transformer.bones[child].direction);
					Vector3d tx = make_vector(0.0, 0.0, 1.0);
					if (length(cross_product(axis_down_bone, tx)) < .0001)
						tx = make_vector(1.0, 0.0, 0.0);
					Vector3d axis_first = normalize(cross_product(axis_down_bone, tx));
					Vector3d axis_second = cross_product(axis_down_bone, axis_first);
					transformer.bones[b].euler_axes[0] = axis_first;
					transformer.bones[b].euler_axes[1] = axis_second;
				}
			}

			Vector3d x = make_vector(0.0, 0.0, 1.0);
			Vector3d y = make_vector(-1.0, 0.0, 0.0);
			Vector3d z = make_vector(0.0, 1.0, 0.0);
				
			// rotate x to axis1 about cross
			Vector3d axis1 = transformer.bones[b].euler_axes[0];
			Vector3d cross = cross_product(x, axis1);
			float costheta = axis1 * x;
			float sintheta = length(cross);
			if (sintheta==0)
					cross = y;
			else
				cross = normalize(cross);
			transformer.bones[b].global_to_local = rotation(atan2(sintheta, costheta), cross);
			assert(length(rotate(x, transformer.bones[b].global_to_local) - axis1) < 10e-5);
			//cout << "Global to local after first axis computation: " << transformer.bones[b].global_to_local << endl;

			// concurrently, y is rotated to y'.
			// next we rotate y' to axis2 about axis1
			Vector3d yprime = rotate(y, transformer.bones[b].global_to_local);
			Vector3d axis2 = transformer.bones[b].euler_axes[1];
			float costheta2 = axis2 * yprime;
			float sintheta2 = length(cross_product(yprime, axis2));
			Quatd r = rotation(atan2(sintheta2, costheta2), axis1);
			//cout << "Cross product of yprime and axis2: " << cross_product(yprime, axis2) << endl;
			//cout << "Axis1: " << axis1 << endl;
			//cout << "Axis2: " << axis2 << endl;
			//cout << "Rotation r of second axis: " << r << endl;
			//cout << "yprime rotated by r: " << rotate(yprime, r) << endl;
			transformer.bones[b].global_to_local = multiply(r, transformer.bones[b].global_to_local);
			transformer.bones[b].dof = "xyz";
			//cout << "axis2 " << axis2 << " axis2 modified by globaltolocal " << rotate(make_vector(0.0,1.0,0.0), transformer.bones[b].global_to_local) << endl;
			//cout << "Global to local after second axis computation: " << transformer.bones[b].global_to_local << endl;
			if (length(rotate(y, transformer.bones[b].global_to_local) - axis2) >= 10e-5) {
				//cout << "rotated: " << rotate(y, transformer.bones[b].global_to_local) << endl;
				//cout << "axis2: " << axis2 << endl;
			}
			assert(length(rotate(y, transformer.bones[b].global_to_local) - axis2) < 10e-5
			|| length(rotate(y, transformer.bones[b].global_to_local) - -axis2) < 10e-5);
			//cout << "axis1 " << axis1 << " axis1 modified by globaltolocal " << rotate(make_vector(1.0,0.0,0.0), transformer.bones[b].global_to_local) << endl;
			//transformer.bones[b].global_to_local = conjugate(transformer.bones[b].global_to_local);
		}

	} // end foreach bone

	transformer.frame_size = 3 * transformer.bones.size() + 6;
}

void to_euler_angles(Character::Pose &pose, Character::Angles &angles, Library::Skeleton &transformer) {
	static vector<double> ang; // for keeping everything in the same hemisphere
	const Library::Skeleton * old_skeleton = pose.skeleton;
	get_euler_skeleton(transformer, *old_skeleton);
	pose.skeleton = &transformer;
	pose.to_angles(angles); // in to_euler_angles
	pose.skeleton = old_skeleton;
}

