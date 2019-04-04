#include "../headers/pch.h"
#include "..\headers\Scene.h"

Scene::Scene()
{
}

Scene::Scene(char* name)
{
	this->name = name;
}

void Scene::setup()
{
	static char* windowNameRGBDB = (char*)"shadow cube (OpenGL RGB DB)";
	static char* windowNameRGB = (char*)"shadow cube (OpenGL RGB)";
	static char* windowNameIndexDB = (char*)"shadow cube (OpenGL Index DB)";
	static char* windowNameIndex = (char*)"shadow cube (OpenGL Index)";
	/* choose visual */
	if (useRGB) {
		if (useDB) {
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
			name = windowNameRGBDB;
		}
		else {
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
			name = windowNameRGB;
		}
	}
	else {
		if (useDB) {
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_INDEX | GLUT_DEPTH);
			name = windowNameIndexDB;
		}
		else {
			glutInitDisplayMode(GLUT_SINGLE | GLUT_INDEX | GLUT_DEPTH);
			name = windowNameIndex;
		}
	}

	glutCreateWindow(name);

	buildColormap();	

	/* setup context */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 30000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -2.0);

	glEnable(GL_DEPTH_TEST);

	if (useLighting) {
		glEnable(GL_LIGHTING);
	}
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
#if 0
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDir);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 80);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25);
#endif

	glEnable(GL_NORMALIZE);

	if (useFog) {
		glEnable(GL_FOG);
	}
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogfv(GL_FOG_INDEX, fogIndex);
	glFogf(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.5);
	glFogf(GL_FOG_START, 1.0);
	glFogf(GL_FOG_END, 3.0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glShadeModel(GL_SMOOTH);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (useLogo) {
		glPolygonStipple((const GLubyte*)sgiPattern);
	}
	else {
		glPolygonStipple((const GLubyte*)shadowPattern);
	}
	printf("Scene setup... done\n");
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

void Scene::drawAxis()
{
	GLfloat axisLength = 0.5f;
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	// draw x axis in red, y axis in green, z axis in blue 
	//glColor3f(1.0f, 0.2f, 0.2f);
	this->setColor(RED);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(axisLength, 0.0f, 0.0f);

	this->setColor(GREEN);
	//glColor3f(0.2f, 1.0f, 0.2f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, axisLength, 0.0f);

	this->setColor(BLUE);
	//glColor3f(0.2f, 0.2f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, axisLength);

	glEnd();
}
