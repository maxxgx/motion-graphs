#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"
#include "Quat.hpp"

#include <assert.h>

template< typename NUM, int ROWS, int COLS >
class Matrix {
public:
	union {
		NUM c[ROWS * COLS];
	};
	NUM &operator()(unsigned int row, unsigned int col) {
		return c[row * COLS + col];
	}
	NUM const &operator()(unsigned int row, unsigned int col) const {
		return c[row * COLS + col];
	}
};

template< typename NUM, int ROWS1, int COLS1, int COLS2 >
Matrix< NUM, ROWS1, COLS2 > operator*(Matrix< NUM, ROWS1, COLS1 > const &a, Matrix< NUM, COLS1, COLS2 > const &b) {
	Matrix< NUM, ROWS1, COLS2 > ret;
	for (unsigned int r = 0; r < ROWS1; ++r) {
		for (unsigned int c = 0; c < COLS2; ++c) {
			ret(r,c) = 0;
			for (unsigned int i = 0; i < COLS1; ++i) {
				ret(r,c) += a(r,i) * b(i, c);
			}
		}
	}
	return ret;
}

template< int SUBROWS, int SUBCOLS, typename NUM, int ROWS, int COLS >
Matrix< NUM, SUBROWS, SUBCOLS > submatrix(Matrix< NUM, ROWS, COLS > const &mat, unsigned int row, unsigned int col) {
	assert(row + SUBROWS <= ROWS);
	assert(col + SUBCOLS <= COLS);
	Matrix< NUM, SUBROWS, SUBCOLS > ret;
	for (unsigned int r = 0; r < SUBROWS; ++r) {
		for (unsigned int c = 0; c < SUBCOLS; ++c) {
			ret(r,c) = mat(row+r,col+c);
		}
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Vector< NUM, ROWS > operator*(Matrix< NUM, ROWS, COLS > const &a, Vector< NUM, COLS > const &b) {
	return make_vector(a * make_matrix(b));
}


template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > operator+(Matrix< NUM, ROWS, COLS > const &a, Matrix< NUM, ROWS, COLS > const &b) {
	Matrix< NUM, ROWS, COLS > ret;
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		ret.c[i] = a.c[i] + b.c[i];
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > operator-(Matrix< NUM, ROWS, COLS > const &a, Matrix< NUM, ROWS, COLS > const &b) {
	Matrix< NUM, ROWS, COLS > ret;
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		ret.c[i] = a.c[i] - b.c[i];
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > operator*(NUM const &a, Matrix< NUM, ROWS, COLS > const &b) {
	Matrix< NUM, ROWS, COLS > ret;
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		ret.c[i] = a * b.c[i];
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > &operator*=(Matrix< NUM, ROWS, COLS > &b, NUM const &a) {
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		b.c[i] *= a;
	}
	return b;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > operator*(Matrix< NUM, ROWS, COLS > const &a, NUM const &b) {
	Matrix< NUM, ROWS, COLS > ret;
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		ret.c[i] = a.c[i] * b;
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > &operator+=(Matrix< NUM, ROWS, COLS > &a, Matrix< NUM, ROWS, COLS > const &b) {
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		a.c[i] += b.c[i];
	}
	return a;
}


template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > operator/(Matrix< NUM, ROWS, COLS > const &a, NUM const &b) {
	Matrix< NUM, ROWS, COLS > ret;
	NUM inv = 1 / b;
	for (unsigned int i = 0; i < ROWS * COLS; ++i) {
		ret.c[i] = a.c[i] * inv;
	}
	return ret;
}


template< typename NUM, int ROWS >
Matrix< NUM, ROWS, 1 > make_matrix(Vector< NUM, ROWS > const &vec) {
	Matrix< NUM, ROWS, 1 > ret;
	for (unsigned int i = 0; i < ROWS; ++i) {
		ret.c[i] = vec.c[i];
	}
	return ret;
}

template< typename NUM, int ROWS >
Vector< NUM, ROWS > make_vector(Matrix< NUM, ROWS, 1 > const &mat) {
	Vector< NUM, ROWS > ret;
	for (unsigned int i = 0; i < ROWS; ++i) {
		ret.c[i] = mat.c[i];
	}
	return ret;
}


template< typename NUM, int ROWS, int COLS >
Matrix< NUM, COLS, ROWS > transpose(Matrix< NUM, ROWS, COLS > const &mat) {
	Matrix< NUM, COLS, ROWS > ret;
	for (unsigned int r = 0; r < ROWS; ++r) {
		for (unsigned int c = 0; c < COLS; ++c) {
			ret(c,r) = mat(r,c);
		}
	}
	return ret;
}

template< typename NUM, int ROWS1, int ROWS2, int COLS1, int COLS2 >
Matrix< NUM, ROWS1 + ROWS2, COLS1 + COLS2 > make_matrix(
	Matrix< NUM, ROWS1, COLS1 > const &m00, Matrix< NUM, ROWS1, COLS2 > const &m01,
	Matrix< NUM, ROWS2, COLS1 > const &m10, Matrix< NUM, ROWS2, COLS2 > const &m11) {

	Matrix< NUM, ROWS1 + ROWS2, COLS1 + COLS2 > ret;
	for (unsigned int r = 0; r < ROWS1; ++r) {
		for (unsigned int c = 0; c < COLS1; ++c) {
			ret(r,c) = m00(r,c);
		}
	}
	for (unsigned int r = 0; r < ROWS1; ++r) {
		for (unsigned int c = 0; c < COLS2; ++c) {
			ret(r,c+COLS1) = m01(r,c);
		}
	}
	for (unsigned int r = 0; r < ROWS2; ++r) {
		for (unsigned int c = 0; c < COLS1; ++c) {
			ret(r+ROWS1,c) = m10(r,c);
		}
	}
	for (unsigned int r = 0; r < ROWS2; ++r) {
		for (unsigned int c = 0; c < COLS2; ++c) {
			ret(r+ROWS1,c+COLS1) = m11(r,c);
		}
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > make_matrix(NUM const *in) {
	Matrix< NUM, ROWS, COLS > ret;
	for (unsigned int i = 0; i < ROWS*COLS; ++i) {
		ret.c[i] = in[i];
	}
	return ret;
}

template< typename NUM, int ROWS, int COLS >
Matrix< NUM, ROWS, COLS > make_matrix(NUM const &in = NUM(0)) {
	Matrix< NUM, ROWS, COLS > ret;
	for (unsigned int i = 0; i < ROWS*COLS; ++i) {
		ret.c[i] = in;
	}
	return ret;
}



template< typename NUM, int RC >
Matrix< NUM, RC, RC > diag(Vector< NUM, RC > const &vec) {
	Matrix< NUM, RC, RC > ret;
	for (unsigned int i = 0; i < RC * RC; ++i) {
		ret.c[i] = 0;
	}
	for (unsigned int i = 0; i < RC; ++i) {
		ret(i,i) = vec.c[i];
	}
	return ret;
}

template< typename NUM, int RC >
Matrix< NUM, RC, RC > diag(NUM const &num) {
	Matrix< NUM, RC, RC > ret;
	for (unsigned int i = 0; i < RC * RC; ++i) {
		ret.c[i] = 0;
	}
	for (unsigned int i = 0; i < RC; ++i) {
		ret(i,i) = num;
	}
	return ret;
}

template< typename NUM >
Matrix< NUM, 3, 3 > cross_product_matrix(Vector< NUM, 3 > const &vec) {
	Matrix< NUM, 3, 3 > ret;
	ret(0,0) =      0; ret(0,1) = -vec.z; ret(0,2) =  vec.y;
	ret(1,0) =  vec.z; ret(1,1) =      0; ret(1,2) = -vec.x;
	ret(2,0) = -vec.y; ret(2,1) =  vec.x; ret(2,2) =      0;
	return ret;
}

template< typename NUM >
Matrix< NUM, 3, 3 > rotation_matrix(Quat< NUM > const &a) {
	NUM wx = a.w * a.x;
	NUM wy = a.w * a.y;
	NUM wz = a.w * a.z;

	NUM xx = a.x * a.x;
	NUM xy = a.x * a.y;
	NUM xz = a.x * a.z;

	NUM yy = a.y * a.y;
	NUM yz = a.y * a.z;

	NUM zz = a.z * a.z;

	NUM res[9] = {
		1 - 2*yy - 2*zz,	2 * xy + 2 * wz,	2 * xz - 2 * wy,
		2 * xy - 2 * wz,	1 - 2*xx - 2*zz,	2 * yz + 2 * wx,
		2 * xz + 2 * wy,	2 * yz - 2 * wx,	1 - 2*xx - 2*yy
	};
	return make_matrix< NUM, 3, 3 >(res);

}

#include <iostream>

template< typename NUM, int ROWS, int COLS >
std::ostream &operator<<(std::ostream &o, Matrix< NUM, ROWS, COLS > const &mat) {
	o << '[';
	for (unsigned int r = 0; r < ROWS; ++r) {
		if (r) o << ";";
		for (unsigned int c = 0; c < COLS; ++c) {
			if (c) o << ", ";
			o << mat(r,c);
		}
	}
	o << ']';
	return o;
}


#endif //MATRIX_HPP
