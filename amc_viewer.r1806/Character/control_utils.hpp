#ifndef CONTROL_UTILS_HPP
#define CONTROL_UTILS_HPP

#include "Character.hpp"

namespace Library {
	class Motion;
};

namespace Character {
	float control_distance(Control const &a, Control const &b);
	float total_control_distance(Library::Motion const &motion, unsigned int start, unsigned int end, Control const &control);
}
#endif //CONTROL_UTILS_HPP
