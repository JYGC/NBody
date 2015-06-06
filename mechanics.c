/*
 * $NBody: mechanics.c 2015/06/06
 * ----------------------------------------------------------------------------
 * <jygchen@gmail.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me some swiss, chedder or brie cheese in
 * return (and maybe a bottle of wine too).   Junying Chen
 * ----------------------------------------------------------------------------
 */

#include "main.h"

#include <stddef.h>
#include <string.h>
#include <math.h>

void gravity_accelx(struct Mass *objlist)
{
	double dx, dy, dz;

	struct Mass *currentact;
	struct Mass *nextact;
	struct Mass *currentobj;
	struct Mass *nextobj;

	nextobj = objlist;
	do {
		currentobj = nextobj;

		nextact = objlist;
		do {
			currentact = nextact;

			if (strcmp(currentobj->name, currentact->name) != 0) {
				dx = currentobj->px - currentact->px;
				dy = currentobj->py - currentact->py;
				dz = currentobj->pz - currentact->pz;

				currentobj->ax += G * (currentact->mass) *
					-dx / pow((dx * dx) + (dy * dy) +
					(dz * dz), 1.5);
			}

			nextact = currentact->nextobj;

		} while (nextact != NULL);

		nextobj = currentobj->nextobj;

	} while (nextobj != NULL);
}

void gravity_accely(struct Mass *objlist)
{
	double dx, dy, dz;

	struct Mass *currentact;
	struct Mass *nextact;
	struct Mass *currentobj;
	struct Mass *nextobj;

	nextobj = objlist;
	do {
		currentobj = nextobj;

		nextact = objlist;
		do {
			currentact = nextact;

			if (strcmp(currentobj->name, currentact->name) != 0) {
				dx = currentobj->px - currentact->px;
				dy = currentobj->py - currentact->py;
				dz = currentobj->pz - currentact->pz;

				currentobj->ay += G * (currentact->mass) *
					-dy / pow((dx * dx) + (dy * dy) +
					(dz * dz), 1.5);
			}

			nextact = currentact->nextobj;

		} while (nextact != NULL);

		nextobj = currentobj->nextobj;

	} while (nextobj != NULL);
}

void gravity_accelz(struct Mass *objlist)
{
	double dx, dy, dz;

	struct Mass *currentact;
	struct Mass *nextact;
	struct Mass *currentobj;
	struct Mass *nextobj;

	nextobj = objlist;
	do {
		currentobj = nextobj;

		nextact = objlist;
		do {
			currentact = nextact;

			if (strcmp(currentobj->name, currentact->name) != 0) {
				dx = currentobj->px - currentact->px;
				dy = currentobj->py - currentact->py;
				dz = currentobj->pz - currentact->pz;

				currentobj->az += G * (currentact->mass) *
					-dz / pow((dx * dx) + (dy * dy) +
					(dz * dz), 1.5);
			}

			nextact = currentact->nextobj;

		} while (nextact != NULL);

		nextobj = currentobj->nextobj;

	} while (nextobj != NULL);
}

void moveobj(struct Mass *objlist)
{
	struct Mass *currentobj;
	struct Mass *nextobj;

	nextobj = objlist;
	do {
		currentobj = nextobj;

		currentobj->vx += currentobj->ax * dt;
		currentobj->vy += currentobj->ay * dt;
		currentobj->vz += currentobj->az * dt;

		currentobj->px += (currentobj->vx + (1/2) * currentobj->ax
				) * dt;
		currentobj->py += (currentobj->vy + (1/2) * currentobj->ay
				) * dt;
		currentobj->pz += (currentobj->vz + (1/2) * currentobj->az
				) * dt;

		currentobj->ax = 0;
		currentobj->ay = 0;
		currentobj->az = 0;

		nextobj = currentobj->nextobj;

	} while (nextobj != NULL);
}
