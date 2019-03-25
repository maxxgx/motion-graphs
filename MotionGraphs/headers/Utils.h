#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

static bool strContains(string s, string sub_s)
{
	return s.find(sub_s) != string::npos;
}

static vector<string> strSplit(string str, char delimiter) {
	vector<string> result;
	std::istringstream iss(str);
	for (std::string s; iss >> s; )
		result.push_back(s);
	return result;
}

/*Returns: -1 if not, a positive long if string is an integer*/
static long is_new_frame(string line) {
	char* p;
	long converted = strtol(line.c_str(), &p, 10);
	if (*p) {
		// conversion failed because the input wasn't a number
		return -1;
	}
	else {
		// use converted
		return converted;
	}
}