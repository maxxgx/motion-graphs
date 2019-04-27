#pragma once
#include "Drawable.h"
#include "Scene.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Cube :
	public Drawable
{
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float xwidth = 1.0f, ywidth = 1.0f, zwidth = 1.0f;
	float length = 1;
	GLfloat cubeXform[4][4];

	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec4 model;

	// Basic constructor: 1-unit length, pos: 0,0,0
	Cube();

	//Deprecated
	// Pos constructor: basic + pos
	Cube(float x, float y, float z);
	// Full constructor: basic + pos + dimens
	Cube(float x, float y, float z, float xwidth, float ywidth, float  zwidth);
	// Construct cube with length
	Cube(float length);

	/*Draw Cube and saves the cube x form matrix to draw shadows*/
	void Drawable::draw();
	void draw(float x, float y, float z);

	/*Draws shadows on ground plane and back plane*/
	void drawShadow(Scene* scene);

	void setPos(float x, float y, float z);
	void setColor(glm::vec4);
	void draw(glm::mat4 model, glm::mat4 view, glm::mat4 proj);

	void setLength(float length);


	~Cube();

private:
	void Init(float x, float y, float z, float xwidth, float ywidth, float  zwidth);
	void myShadowMatrix(float ground[4], float light[4]);
	
	unsigned int VBO, VAO;

	float vertices[108] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
	};
};

