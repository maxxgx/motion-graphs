#include "..\headers\CubeCore.h"

CubeCore::CubeCore()
{
}

CubeCore::CubeCore(glm::vec3 pos)
{
	this->pos = pos;
}

CubeCore::CubeCore(float x, float y, float z)
{
	this->pos = glm::vec3(x, y, z);
}

void CubeCore::setBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * ver.size(), ver.data(), GL_STATIC_DRAW);
	
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

CubeCore::~CubeCore()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
