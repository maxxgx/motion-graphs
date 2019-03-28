#include "../headers/pch.h"
#include "../headers/Cube.h"

void Cube::Init(float x, float y, float z, float xwidth, float ywidth, float zwidth)
{
	this->x = x; this->y = y; this->z = z;
	this->xwidth = xwidth; this->ywidth = ywidth; this->zwidth = zwidth;
}

Cube::Cube()
{
	Init(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
}

Cube::Cube(float x, float y, float z)
{
	Init(x, y, z, 1.0f, 1.0f, 1.0f);
}

Cube::Cube(float x, float y, float z, float xwidth, float ywidth, float zwidth)
{
	Init(x, y, z, xwidth, ywidth, zwidth);
}

Cube::Cube(float length)
{
	Init(0.0f, 0.0f, 0.0f, length, 1.0f, 1.0f);
}

void Cube::draw()
{
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)cubeXform);

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(xwidth, ywidth, zwidth);

	glutSolidCube(1);
	glPopMatrix();
}



void Cube::drawShadow(Scene* scene)
{
	//ground
	glPushMatrix();
	myShadowMatrix(scene->groundPlane, scene->lightPos);
	glTranslatef(0.0, 0.0, 2.0);
	glMultMatrixf((const GLfloat*)cubeXform);

	scene->setColor(BLACK);
	this->draw();      /* draw ground shadow */
	glPopMatrix();

	//backplane
	glPushMatrix();
	myShadowMatrix(scene->backPlane, scene->lightPos);
	glTranslatef(0.0, 0.0, 2.0);
	glMultMatrixf((const GLfloat*)cubeXform);

	scene->setColor(BLACK);
	this->draw();      /* draw ground shadow */
	glPopMatrix();
}

void Cube::setPos(float x, float y, float z)
{
	this->x = x; this->y = y; this->z = z;
}

Cube::~Cube()
{
}


void Cube::myShadowMatrix(float ground[4], float light[4])
{
	float dot;
	float shadowMat[4][4];

	dot = ground[0] * light[0] +
		ground[1] * light[1] +
		ground[2] * light[2] +
		ground[3] * light[3];

	shadowMat[0][0] = dot - light[0] * ground[0];
	shadowMat[1][0] = 0.0 - light[0] * ground[1];
	shadowMat[2][0] = 0.0 - light[0] * ground[2];
	shadowMat[3][0] = 0.0 - light[0] * ground[3];

	shadowMat[0][1] = 0.0 - light[1] * ground[0];
	shadowMat[1][1] = dot - light[1] * ground[1];
	shadowMat[2][1] = 0.0 - light[1] * ground[2];
	shadowMat[3][1] = 0.0 - light[1] * ground[3];

	shadowMat[0][2] = 0.0 - light[2] * ground[0];
	shadowMat[1][2] = 0.0 - light[2] * ground[1];
	shadowMat[2][2] = dot - light[2] * ground[2];
	shadowMat[3][2] = 0.0 - light[2] * ground[3];

	shadowMat[0][3] = 0.0 - light[3] * ground[0];
	shadowMat[1][3] = 0.0 - light[3] * ground[1];
	shadowMat[2][3] = 0.0 - light[3] * ground[2];
	shadowMat[3][3] = dot - light[3] * ground[3];

	glMultMatrixf((const GLfloat*)shadowMat);
}
