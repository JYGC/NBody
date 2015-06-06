/*
 * $NBody: mass.c 2015/06/06
 * ----------------------------------------------------------------------------
 * <jygchen@gmail.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me some swiss, chedder or brie cheese in
 * return (and maybe a bottle of wine too).   Junying Chen
 * ----------------------------------------------------------------------------
 */

#include "main.h"

#include <stdlib.h>
#include <string.h>

void newmass(char *name, double mass, double px, double py, double pz,
    double vx, double vy, double vz, float rcolor, float gcolor, float bcolor)
{
	struct Mass *currentobj;

	if (glob_massobjlist == NULL) {
		glob_massobjlist = malloc(sizeof(struct Mass));
		currentobj = glob_massobjlist;
	} else {
		currentobj = glob_massobjlist;
		while (currentobj->nextobj != NULL)
			currentobj = currentobj->nextobj;
		currentobj->nextobj = malloc(sizeof(struct Mass));
		currentobj = currentobj->nextobj;
	}

	currentobj->name = malloc((strlen(name) + 1) * sizeof(char));
	strncpy(currentobj->name, name, strlen(name) + 1);
	currentobj->mass = mass;
	currentobj->px = px;
	currentobj->py = py;
	currentobj->pz = pz;
	currentobj->vx = vx;
	currentobj->vy = vy;
	currentobj->vz = vz;
	currentobj->rcolor = rcolor;
	currentobj->gcolor = gcolor;
	currentobj->bcolor = bcolor;
	currentobj->nextobj = NULL;
}

void printallmass(FILE *fp)
{
	struct Mass *currentobj;

	currentobj = glob_massobjlist;

	while (currentobj != NULL) {
                fprintf(fp, "-- %s --\n", currentobj->name);
                fprintf(fp, "Mass: %f\n", currentobj->mass);
                fprintf(fp, "Position: [%f, %f, %f]\n", currentobj->px,
			currentobj->py, currentobj->pz);
		fprintf(fp, "Velocity: [%f, %f, %f]\n", currentobj->vx,
			currentobj->vy, currentobj->vz);
		fprintf(fp, "Color: [%f, %f, %f]\n", currentobj->rcolor,
			currentobj->gcolor, currentobj->bcolor);
		fprintf(fp,"\n\n");

		currentobj = currentobj->nextobj;
	}
}
