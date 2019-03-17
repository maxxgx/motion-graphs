/** Headers **/
#include "../headers/pch.h"
#include "../headers/Cube.h"
#include "../headers/Scene.h"
#include <stdio.h>
#include <tchar.h>
#include <string>

using namespace std;

static int frame_time = 0;

Scene* scene = new Scene();
Cube* cube = new Cube(0, 0, 0, 2, 1, 1);

static int tick = -1;
static int moving = 1;

static void
usage(void)
{
	printf("\n");
	printf("usage: scube [options]\n");
	printf("\n");
	printf("    display a spinning cube and its shadow\n");
	printf("\n");
	printf("  Options:\n");
	printf("    -geometry  window size and location\n");
	printf("    -c         toggle color index mode\n");
	printf("    -l         toggle lighting\n");
	printf("    -f         toggle fog\n");
	printf("    -db        toggle double buffering\n");
	printf("    -logo      toggle sgi logo for the shadow pattern\n");
	printf("    -quads     toggle use of GL_QUADS to draw the checkerboard\n");
	printf("\n");
#ifndef EXIT_FAILURE    /* should be defined by ANSI C
						   <stdlib.h> */
#define EXIT_FAILURE 1
#endif
	exit(EXIT_FAILURE);
}

static char* windowNameRGBDB = (char*)"shadow cube (OpenGL RGB DB)";
static char* windowNameRGB = (char*)"shadow cube (OpenGL RGB)";
static char* windowNameIndexDB = (char*)"shadow cube (OpenGL Index DB)";
static char* windowNameIndex = (char*)"shadow cube (OpenGL Index)";

void
idle(void)
{
	tick++;
	if (tick >= 120) {
		tick = 0;
	}
	glutPostRedisplay();
}

/* ARGSUSED1 */
void
keyboard(unsigned char ch, int x, int y)
{
	switch (ch) {
	case 27:             /* escape */
		exit(0);
		break;
	case 'L':
	case 'l':
		scene->useLighting = !scene->useLighting;
		scene->useLighting ? glEnable(GL_LIGHTING) :
			glDisable(GL_LIGHTING);
		glutPostRedisplay();
		break;
	case 'F':
	case 'f':
		scene->useFog = !scene->useFog;
		scene->useFog ? glEnable(GL_FOG) : glDisable(GL_FOG);
		glutPostRedisplay();
		break;
	case '1':
		glFogf(GL_FOG_MODE, GL_LINEAR);
		glutPostRedisplay();
		break;
	case '2':
		glFogf(GL_FOG_MODE, GL_EXP);
		glutPostRedisplay();
		break;
	case '3':
		glFogf(GL_FOG_MODE, GL_EXP2);
		glutPostRedisplay();
		break;
	case ' ':
		if (!moving) {
			idle();
			glutPostRedisplay();
		}
	}
}


void
display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0, -1.5, 0.0);
	glRotatef(-90.0, 1, 0, 0);
	glScalef(2.0, 2.0, 2.0);

	scene->drawCheckPlane(10, 10, BLUE, GREY);  /* draw ground */
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.9);
	glScalef(2.0, 2.0, 2.0);

	scene->drawCheckPlane(10, 10, BLUE, GREY);  /* draw back */
	glPopMatrix();

	/*Draw cube*/
	glPushMatrix();
	glTranslatef(0.0, 0.2, 0.0);
	glScalef(0.3, 0.3, 0.3);
	glRotatef((360.0 / (30 * 1)) * tick, 1, 0, 0);
	glRotatef((360.0 / (30 * 2)) * tick, 0, 1, 0);
	glRotatef((360.0 / (30 * 4)) * tick, 0, 0, 1);
	glScalef(1.0, 2.0, 1.0);

	//drawCube(RED);        /* draw cube */
	scene->setColor(RED);
	cube->z = -1;
	cube->draw();
	//glutSolidCube(1);
	glPopMatrix();


	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	if (scene->useFog) {
		glDisable(GL_FOG);
	}
	cube->drawShadow(scene);


	int fps = glutGet(GLUT_ELAPSED_TIME);
	std::string s_fps = "FPS: " + std::to_string(fps);

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	if (scene->useFog) {
		glEnable(GL_FOG);
	}
	if (scene->useDB) {
		glutSwapBuffers();
	}
	else {
		glFlush();
	}
}

void
fog_select(int fog)
{
	glFogf(GL_FOG_MODE, fog);
	glutPostRedisplay();
}

void
menu_select(int mode)
{
	switch (mode) {
	case 1:
		moving = 1;
		glutIdleFunc(idle);
		break;
	case 2:
		moving = 0;
		glutIdleFunc(NULL);
		break;
	case 3:
		scene->useFog = !scene->useFog;
		scene->useFog ? glEnable(GL_FOG) : glDisable(GL_FOG);
		glutPostRedisplay();
		break;
	case 4:
		scene->useLighting = !scene->useLighting;
		scene->useLighting ? glEnable(GL_LIGHTING) :
			glDisable(GL_LIGHTING);
		glutPostRedisplay();
		break;
	case 5:
		exit(0);
		break;
	}
}

void
visible(int state)
{
	if (state == GLUT_VISIBLE) {
		if (moving)
			glutIdleFunc(idle);
	}
	else {
		if (moving)
			glutIdleFunc(NULL);
	}
}

int
main(int argc, char** argv)
{
	int width = 800, height = 800;
	int i;
	char* name;
	int fog_menu;

	glutInitWindowSize(width, height);
	glutInit(&argc, argv);

	scene->setup();

	fog_menu = glutCreateMenu(fog_select);
	glutAddMenuEntry("Linear fog", GL_LINEAR);
	glutAddMenuEntry("Exp fog", GL_EXP);
	glutAddMenuEntry("Exp^2 fog", GL_EXP2);

	glutCreateMenu(menu_select);
	glutAddMenuEntry("Start motion", 1);
	glutAddMenuEntry("Stop motion", 2);
	glutAddMenuEntry("Toggle fog", 3);
	glutAddMenuEntry("Toggle lighting", 4);
	glutAddSubMenu("Fog type", fog_menu);
	glutAddMenuEntry("Quit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutVisibilityFunc(visible);

	//Background color
	glClearColor(0.4, 0.4, 0.4, 1);
	glClearIndex(0);
	glClearDepth(1);

	glutMainLoop();
	return 0;             /* ANSI C requires main to return int. */
}
