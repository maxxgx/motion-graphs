#ifndef CHARACTER_SKIN_UTILS_HPP
#define CHARACTER_SKIN_UTILS_HPP

#include "Skin.hpp"
#include <string>
namespace Character {
	bool load(std::string const &filename, Library::Skeleton const *on, Skin &into, bool shadow = false);
} //namespace Character

#endif //CHARACTER_SKIN_UTILS_HPP
