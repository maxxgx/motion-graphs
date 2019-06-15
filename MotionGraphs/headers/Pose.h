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
	Pose(long frame);

	vector<float> getBoneTrans(int id);

	int getPoseFrame();
	
	void addTransf(int id, vector<float> transf);

	~Pose();

private:
	int frame;
	vector<vector<float>> transf;
};