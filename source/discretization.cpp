#include "..\include\discretization.h"

double FO_fwrd_diff(int i, double *u, double dx)
{
    return (*(u + i + 1) - *(u + i)) / dx;
}

double FO_bwrd_diff(int i, double *u, double dx)
{
    return (*(u + i) - *(u + i - 1)) / dx;
}

double SO_ctrl_diff(int i, double *u, double dx)
{
    return (*(u + i + 1) - *(u + i - 1)) / (2 * dx);
}