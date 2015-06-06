/*
 * $NBody: auxillary.c 2015/06/06
 * ----------------------------------------------------------------------------
 * <jygchen@gmail.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me some swiss, chedder or brie cheese in
 * return (and maybe a bottle of wine too).   Junying Chen
 * ----------------------------------------------------------------------------
 */

#include "main.h"

#include <stdio.h>
#include <stdbool.h>

void getobj_stdin(FILE *fp)
{
	int ret;
        char name[1000000];
        float mass;
        float px, py, pz;
        float vx, vy, vz;
        float rcolor, gcolor, bcolor;

        while(true) {
		ret = fscanf(stdin, "%s %f %f %f %f %f %f %f %f %f %f", name,
			&mass, &px, &py, &pz, &vx, &vy, &vz, &rcolor, &gcolor,
			&bcolor);

		if (ret == 11)
			newmass(name, mass, px, py, pz, vx, vy, vz, rcolor,
				gcolor, bcolor);
		else if (ret == EOF)
			break;

	}
}
