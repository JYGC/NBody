/*
 * mass.h
 *
 *  Created on: 19 May 2015
 *      Author: junying
 */

#ifndef MASS_H_
#define MASS_H_

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

	struct Mass *nextobj;
};

void newmass(char *, double, double, double, double, double, double, double);

#endif /* MASS_H_ */
