#include "../headers/pch.h"
#include "..\headers\Scene.h"

Scene::Scene()
{
}

void Scene::drawCheckPlane(int w, int h, int evenColor, int oddColor)
{
	static int initialized = 0;
	static int usedLighting = 0;
	static GLuint checklist = 0;

	if (!initialized || (usedLighting != useLighting)) {
		static float square_normal[4] =
		{ 0.0, 0.0, 1.0, 0.0 };
		static float square[4][4];
		int i, j;

		if (!checklist) {
			checklist = glGenLists(1);
		}
		glNewList(checklist, GL_COMPILE_AND_EXECUTE);

		if (useQuads) {
			glNormal3fv(square_normal);
			glBegin(GL_QUADS);
		}
		for (j = 0; j < h; ++j) {
			for (i = 0; i < w; ++i) {
				square[0][0] = -1.0 + 2.0 / w * i;
				square[0][1] = -1.0 + 2.0 / h * (j + 1);
				square[0][2] = 0.0;
				square[0][3] = 1.0;

				square[1][0] = -1.0 + 2.0 / w * i;
				square[1][1] = -1.0 + 2.0 / h * j;
				square[1][2] = 0.0;
				square[1][3] = 1.0;

				square[2][0] = -1.0 + 2.0 / w * (i + 1);
				square[2][1] = -1.0 + 2.0 / h * j;
				square[2][2] = 0.0;
				square[2][3] = 1.0;

				square[3][0] = -1.0 + 2.0 / w * (i + 1);
				square[3][1] = -1.0 + 2.0 / h * (j + 1);
				square[3][2] = 0.0;
				square[3][3] = 1.0;

				if (i & 1 ^ j & 1) {
					setColor(oddColor);
				}
				else {
					setColor(evenColor);
				}

				if (!useQuads) {
					glBegin(GL_POLYGON);
				}
				glVertex4fv(&square[0][0]);
				glVertex4fv(&square[1][0]);
				glVertex4fv(&square[2][0]);
				glVertex4fv(&square[3][0]);
				if (!useQuads) {
					glEnd();
				}
			}
		}

		if (useQuads) {
			glEnd();
		}
		glEndList();

		initialized = 1;
		usedLighting = useLighting;
	}
	else {
		glCallList(checklist);
	}
}

Scene::~Scene()
{
}

void Scene::setColor(int c)
{
	if (useLighting) {
		if (useRGB) {
			glMaterialfv(GL_FRONT_AND_BACK,
				GL_AMBIENT_AND_DIFFUSE, &materialColor[c][0]);
		}
		else {
			glMaterialfv(GL_FRONT_AND_BACK,
				GL_COLOR_INDEXES, &materialColor[c][0]);
		}
	}
	else {
		if (useRGB) {
			glColor4fv(&materialColor[c][0]);
		}
		else {
			glIndexf(materialColor[c][1]);
		}
	}
}

void Scene::buildColormap(void)
{
	if (useRGB) {
		return;
	}
	else {
		int mapSize = 1 << glutGet(GLUT_WINDOW_BUFFER_SIZE);
		int rampSize = mapSize / 8;
		int entry;
		int i;

		for (entry = 0; entry < mapSize; ++entry) {
			int hue = entry / rampSize;
			GLfloat val = (entry % rampSize) * (1.0 / (rampSize - 1));
			GLfloat red, green, blue;

			red = (hue == 0 || hue == 1 || hue == 5 || hue == 6) ? val : 0;
			green = (hue == 0 || hue == 2 || hue == 4 || hue == 6) ? val : 0;
			blue = (hue == 0 || hue == 3 || hue == 4 || hue == 5) ? val : 0;

			glutSetColor(entry, red, green, blue);
		}

		for (i = 0; i < 8; ++i) {
			materialColor[i][0] = i * rampSize + 0.2 * (rampSize - 1);
			materialColor[i][1] = i * rampSize + 0.8 * (rampSize - 1);
			materialColor[i][2] = i * rampSize + 1.0 * (rampSize - 1);
			materialColor[i][3] = 0.0;
		}

		fogIndex[0] = -0.2 * (rampSize - 1);
	}
}
