/*
 * $NBody: main.c 2015/06/06
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

struct Mass *glob_massobjlist = NULL;
long double glob_time = 0;

int main(int argc, char **argv)
{
	getobj_stdin(stdin);

	printallmass(stdout);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("NBody Sim");
	glutDisplayFunc(draw);
	glutMainLoop();
}
