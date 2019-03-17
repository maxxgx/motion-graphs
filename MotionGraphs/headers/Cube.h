#pragma once
#include "Drawable.h"
#include "Scene.h"

class Cube :
	public Drawable
{
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float xwidth = 1.0f, ywidth = 1.0f, zwidth = 1.0f;
	GLfloat cubeXform[4][4];

	// Basic constructor: 1-unit length, pos: 0,0,0
	Cube();
	// Pos constructor: basic + pos
	Cube(float x, float y, float z);
	// Full constructor: basic + pos + dimens
	Cube(float x, float y, float z, float xwidth, float ywidth, float  zwidth);

	/*Draw Cube and saves the cube x form matrix to draw shadows*/
	void Drawable::draw();

	/*Draws shadows on ground plane and back plane*/
	void drawShadow(Scene *scene);
	

	~Cube();

private:
	void Init(float x, float y, float z, float xwidth, float ywidth, float  zwidth);
	void myShadowMatrix(float ground[4], float light[4]);
};

