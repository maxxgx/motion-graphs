#ifndef CHARACTER_RENDER_HPP
#define CHARACTER_RENDER_HPP
#include <string>
using std::string;

#include "Character.hpp"

namespace Character {
	//draw a pose!
	void draw(Pose const &pose, State const &state, bool detail=true, bool color=true, bool select=false, float alpha = 1.0f, string bubble = "");
	//draw a control!
	void draw(Control const &control, State const &state);
	//draw a state!
	void draw(State const &state);
};

#endif //CHARACTER_RENDER_HPP
