#ifndef _DISCRETIZATION_H_
#define _DISCRETIZATION_H_
double FO_fwrd_diff(int i, double *u, double dx);
double FO_bwrd_diff(int i, double *u, double dx);
double SO_ctrl_diff(int i, double *u, double dx);
#endif