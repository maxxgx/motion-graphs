#ifndef VECTOR_MISC_HPP
#define VECTOR_MISC_HPP

//Miscellaneous useful but not so useful as to be in the main header functions.

inline Vector3f rotate_by_yaw(Vector3f const &in, float const yaw) {
	float c = cosf(yaw);
	float s = sinf(yaw);
	return make_vector< float >(s * in.z + c * in.x, in.y, c * in.z - s * in.x);
}

#endif //VECTOR_MISC_HPP
