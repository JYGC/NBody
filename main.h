/*
 * $NBody: main.h 2015/06/06
 * ----------------------------------------------------------------------------
 * <jygchen@gmail.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me some swiss, chedder or brie cheese in
 * return (and maybe a bottle of wine too).   Junying Chen
 * ----------------------------------------------------------------------------
 */

#include <stdio.h>

#ifndef MASS
#define MASS
struct Mass {

	char *name;
	double mass;

	double px;
	double py;
	double pz;

	double vx;
	double vy;
	double vz;

	double ax;
	double ay;
	double az;

	float rcolor;
	float gcolor;
	float bcolor;

	struct Mass *nextobj;
};

void newmass(char *, double, double, double, double, double, double, double,
    float, float, float);
void printallmass(FILE *);
#endif /* MASS */


#ifndef MECHANICS
#define MECHANICS
void gravity_accelx(struct Mass *);
void gravity_accely(struct Mass *);
void gravity_accelz(struct Mass *);
void moveobj(struct Mass *);
#endif /* MECHANICS */


#ifndef AUXILLARY
#define AUXILLARY
void getobj_stdin(FILE *);
#endif /* AUXILLARY */


#ifndef DRAW
#define DRAW
void draw(void);
#endif /* DRAW */


#ifndef MAIN
#define MAIN
#define G 0.000001
#define dt 0.01
extern struct Mass *glob_massobjlist;
extern long double glob_time;
#endif /* MAIN */
