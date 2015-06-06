/*
 * $NBody: draw.c 2015/06/06
 * ----------------------------------------------------------------------------
 * <jygchen@gmail.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me some swiss, chedder or brie cheese in
 * return (and maybe a bottle of wine too).   Junying Chen
 * ----------------------------------------------------------------------------
 */

#include "main.h"

#include <stdio.h>

#include <GL/glut.h>

void draw(void)
{
	struct Mass *currentobj;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

	currentobj = glob_massobjlist;
	while (currentobj != NULL) {
		glColor3f(currentobj->rcolor, currentobj->gcolor,
			currentobj->bcolor);
		glVertex3f(currentobj->px, currentobj->py, currentobj->pz);

		printf("[%f,%f,%f] ", currentobj->px, currentobj->py,
			currentobj->pz);

		gravity_accelx(glob_massobjlist);
		gravity_accely(glob_massobjlist);
		gravity_accelz(glob_massobjlist);
		moveobj(glob_massobjlist);

		currentobj = currentobj->nextobj;
	}
	printf("\n");

	glEnd();
	glFlush();

	glutPostRedisplay();

	glob_time += dt;
}
