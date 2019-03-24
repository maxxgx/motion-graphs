#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
* A pose contains the trasformations of the a frame
*/
class Pose
{
public:
	Pose();

	vector<double> getBoneTrans(string bone);

	int getPoseFrame();

	~Pose();

private:
	int frame;
	map<string, vector<double>> transf;
};