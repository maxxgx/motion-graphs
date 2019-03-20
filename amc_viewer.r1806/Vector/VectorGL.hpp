#ifndef VECTOR_GL_HPP
#define VECTOR_GL_HPP 1

//include your favorite opengl header first.

//----- int ------

inline void glVertex(Vector< GLint, 2 > const &v) {
	glVertex2iv(v.c);
}

inline void glVertex(Vector2i const &v, int const &z) {
	glVertex3i(v.c[0], v.c[1], z);
}

inline void glVertex(Vector3i const &v, int const &z) {
	glVertex4i(v.c[0], v.c[1], v.c[2], z);
}

inline void glVertex(Vector< GLint, 3 > const &v) {
	glVertex3iv(v.c);
}

//----- double ------

inline void glVertex(Vector2d const &v) {
	glVertex2dv(v.c);
}

inline void glVertex(Vector2d const &v, double const &z) {
	glVertex3d(v.c[0], v.c[1], z);
}

inline void glVertex(Vector3d const &v, double const &z) {
	glVertex4d(v.c[0], v.c[1], v.c[2], z);
}

inline void glVertex(Vector3d const &v) {
	glVertex3dv(v.c);
}

//----- float ------

inline void glVertex(Vector2f const &v) {
	glVertex2fv(v.c);
}

inline void glVertex(Vector2f const &v, float const &z) {
	glVertex3f(v.c[0], v.c[1], z);
}

inline void glVertex(Vector3f const &v, float const &z) {
	glVertex4f(v.c[0], v.c[1], v.c[2], z);
}

inline void glVertex(Vector3f const &v) {
	glVertex3fv(v.c);
}

//---- int ----

inline void glNormal(Vector< GLint, 3 > const &v) {
	glNormal3iv(v.c);
}

inline void glNormal(Vector2i const &v, int &z) {
	glNormal3i(v.c[0], v.c[1], z);
}

//---- double ----

inline void glNormal(Vector3d const &v) {
	glNormal3dv(v.c);
}

inline void glNormal(Vector2d const &v, double &z) {
	glNormal3d(v.c[0], v.c[1], z);
}

//---- float ----

inline void glNormal(Vector3f const &v) {
	glNormal3fv(v.c);
}

inline void glNormal(Vector2f const &v, float &z) {
	glNormal3f(v.c[0], v.c[1], z);
}

//---- double ----

inline void glColor(Vector3d const &v) {
	glColor3dv(v.c);
}

inline void glColor(Vector3d const &v, double a) {
	glColor4d(v.c[0], v.c[1], v.c[2], a);
}

inline void glColor(Vector< double, 4 > const &v) {
	glColor4dv(v.c);
}

inline void glColor(Vector3f const &v) {
	glColor3fv(v.c);
}

inline void glColor(Vector3f const &v, float a) {
	glColor4f(v.c[0], v.c[1], v.c[2], a);
}

inline void glColor(Vector< float, 4 > const &v) {
	glColor4fv(v.c);
}

inline void glTexCoord(Vector2d const &v) {
	glTexCoord2dv(v.c);
}

inline void glTexCoord(Vector2f const &v) {
	glTexCoord2fv(v.c);
}

inline void glTranslate(Vector< float, 2 > const &v, float z = 0) {
	glTranslatef(v.c[0], v.c[1], z);
}

inline void glTranslate(Vector< float, 3 > const &v) {
	glTranslatef(v.c[0], v.c[1], v.c[2]);
}

inline void glTranslate(Vector< double, 2 > const &v, double z = 0) {
	glTranslated(v.c[0], v.c[1], z);
}

inline void glTranslate(Vector< double, 3 > const &v) {
	glTranslated(v.c[0], v.c[1], v.c[2]);
}


#endif
