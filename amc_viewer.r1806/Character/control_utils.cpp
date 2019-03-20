#include "control_utils.hpp"

#include <Library/Library.hpp>

namespace Character {

float control_distance(Control const &a, Control const &b) {
	float dis = 0.0f;
	{ //handle relative velocity:
		float len_a = length(a.desired_velocity);
		float len_b = length(b.desired_velocity);
		dis += fabs(len_a - len_b);
		//handle relative angle:
		if (len_a > 0.0f && len_b > 0.0f) {
			dis += fabs(1.0f - (a.desired_velocity * b.desired_velocity) / (len_a * len_b));
		}
	}
	//handle_relative turning:
	dis += fabs(a.desired_turning - b.desired_turning);
	//handle jumping:
	if (a.jump != b.jump) dis += 5.0f;
	return dis;
}

float total_control_distance(Library::Motion const &motion, unsigned int start, unsigned int end, Control const &control) {
	float dis = 0.0f;
	for (unsigned int frame = start; frame < end; ++frame) {
		Control motion_control;
		motion.get_control(frame, motion_control);
		dis += control_distance(motion_control, control);
	}
	return dis;
}

}
