#ifndef ROOTED_VECTOR_HPP
#define ROOTED_VECTOR_HPP

#include "Vector.hpp"

template< typename NUM, int size >
class RootedVector {
public:
	Vector< NUM, size > root;
	Vector< NUM, size > vec;
};

template< typename NUM, int size >
inline RootedVector< NUM, size > make_rooted_vector( Vector< NUM, size > const &root, Vector< NUM, size > const &vec ) {
	RootedVector< NUM, size > ret;
	ret.root = root;
	ret.vec = vec;
	return ret;
}


typedef RootedVector< int, 2 > RootedVector2i;
typedef RootedVector< int, 3 > RootedVector3i;
typedef RootedVector< int, 4 > RootedVector4i;

typedef RootedVector< float, 2 > RootedVector2f;
typedef RootedVector< float, 3 > RootedVector3f;
typedef RootedVector< float, 4 > RootedVector4f;

typedef RootedVector< double, 2 > RootedVector2d;
typedef RootedVector< double, 3 > RootedVector3d;
typedef RootedVector< double, 4 > RootedVector4d;

#endif //ROOTED_VECTOR_HPP
