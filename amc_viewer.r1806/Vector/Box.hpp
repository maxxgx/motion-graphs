#ifndef BOX_HPP
#define BOX_HPP

#include "Vector.hpp"

template< typename NUM, int Size >
class Box {
public:
	Vector< NUM, Size > min;
	Vector< NUM, Size > max;
	bool contains(Vector< NUM, Size > const &p) const {
		bool ret = true;
		for (unsigned int c = 0; c < Size; ++c) {
			ret = ret && (p.c[c] >= min.c[c]);
			ret = ret && (p.c[c] <= max.c[c]);
		}
		return ret;
	}
	bool intersects(Box< NUM, Size > const &b) const {
		bool ret = true;
		for (unsigned int c = 0; c < Size; ++c) {
			ret = ret && !(min.c[c] > b.max.c[c]);
			ret = ret && !(max.c[c] < b.min.c[c]);
		}
		return ret;
	}
	Vector< NUM, Size > clamp(Vector< NUM, Size > const &in) const {
		Vector< NUM, Size > ret;
		for (unsigned int c = 0; c < Size; ++c) {
			if (in.c[c] < min.c[c]) ret.c[c] = min.c[c];
			else if (in.c[c] > max.c[c]) ret.c[c] = max.c[c];
			else ret.c[c] = in.c[c];
		}
		return ret;
	}
	//if 'vec' is in the coordinate system of this box, return it in the coordinate system of target (assuming that this box and target end up in the same place).
	Vector< NUM, Size > project(Vector< NUM, Size > const &vec, Box< NUM, Size > const &target) {
		Vector< NUM, Size > ret;
		for (unsigned int c = 0; c < Size; ++c) {
			if (min.c[c] == max.c[c]) {
				ret.c[c] = min[c];
			} else {
				ret.c[c] = (target.max.c[c] - target.min.c[c]) * (vec.c[c] - min.c[c]) / (max.c[c] - min.c[c]) + target.min.c[c];
			}
		}
		return ret;
	}
	Vector< NUM, Size > center() const {
		return 0.5f * (min + max);
	}
	Vector< NUM, Size > size() const {
		return max - min;
	}
};

template< typename NUM, int size >
inline Box< NUM, size > make_box(Vector< NUM, size > const &min, Vector< NUM, size > const &max) {
	Box< NUM, size > box;
	box.min = min;
	box.max = max;
	return box;
}

typedef Box< int, 2 > Box2i;
typedef Box< int, 3 > Box3i;
typedef Box< int, 4 > Box4i;

typedef Box< float, 2 > Box2f;
typedef Box< float, 3 > Box3f;
typedef Box< float, 4 > Box4f;

typedef Box< double, 2 > Box2d;
typedef Box< double, 3 > Box3d;
typedef Box< double, 4 > Box4d;

#endif //BOX_HPP
