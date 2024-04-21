#include "..\include\discretization.h"

double FO_fwrd_diff(int i, double *u, double dx)
{
    return (*(u + 1) - *u) / dx;
}

double FO_bwrd_diff(int i, double *u, double dx)
{
    return (*(u) - *(u - 1)) / dx;
}

double SO_ctrl_diff(int i, double *u, double dx)
{
    return (*(u + 1) - *(u - 1)) / (2 * dx);
}