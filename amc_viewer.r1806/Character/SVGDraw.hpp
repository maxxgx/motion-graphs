#ifndef CHARACTER_SVGDRAW_HPP
#define CHARACTER_SVGDRAW_HPP

#include "Character.hpp"

#include <string>
using std::string;
#include <iostream>
using std::ostream;

namespace Character {

	void start_draw(ostream &svg_file); //writes svg header
	void draw(ostream &svg_file, Pose const &pose, State const &state, bool detail = true, bool color = true);
	void finish_draw(ostream &svg_file); //does final depth sort, output, writes footer

};

#endif //CHARACTER_SVGDRAW_HPP
