#ifndef QUAT_GL_HPP
#define QUAT_GL_HPP

#include "Quat.hpp"

template< typename NUM >
void quat_to_gl_matrix(Quat< NUM > const &a, NUM *mat) {
	NUM wx = a.w * a.x;
	NUM wy = a.w * a.y;
	NUM wz = a.w * a.z;

	NUM xx = a.x * a.x;
	NUM xy = a.x * a.y;
	NUM xz = a.x * a.z;

	NUM yy = a.y * a.y;
	NUM yz = a.y * a.z;

	NUM zz = a.z * a.z;

	NUM res[16] = {
		1 - 2*yy - 2*zz,	2 * xy + 2 * wz,	2 * xz - 2 * wy,	0,
		2 * xy - 2 * wz,	1 - 2*xx - 2*zz,	2 * yz + 2 * wx,	0,
		2 * xz + 2 * wy,	2 * yz - 2 * wx,	1 - 2*xx - 2*yy,	0,
		0,					0,					0,					1
	};

	for (unsigned int i = 0; i < 16; ++i) {
		mat[i] = res[i];
	}
}

inline void glRotate(Quat< double > const &a) {
	double mat[16];
	quat_to_gl_matrix(a, mat);
	glMultMatrixd(mat);
}

inline void glRotate(Quat< float > const &a) {
	float mat[16];
	quat_to_gl_matrix(a, mat);
	glMultMatrixf(mat);
}

#endif
