#include "..\include\discretization.h"

double FO_fwrd_diff(int i, double *u, double dx, int arr_len)
{
    if (i == arr_len - 1)
    {
        return (-(*(u + i - 2)) + 4 * (*(u + i - 1)) - 3 * (*(u + i))) / (2 * dx);
    }
    else
    {
        return (*(u + i + 1) - *(u + i)) / dx;
    }
}

double FO_bwrd_diff(int i, double *u, double dx, int arr_len)
{
    if (i == 0)
    {
        return (-3 * (*(u + i)) + 4 * (*(u + i + 1)) - (*(u + i + 2))) / (2 * dx);
    }
    else
    {
        return (*(u + i) - *(u + i - 1)) / dx;
    }
}

double SO_ctrl_diff(int i, double *u, double dx, int arr_len)
{
    if (i == 0)
    {
        return (-3 * (*(u + i)) + 4 * (*(u + i + 1)) - (*(u + i + 2))) / (2 * dx);
    }
    else if (i == arr_len - 1)
    {
        return (-(*(u + i - 2)) + 4 * (*(u + i - 1)) - 3 * (*(u + i))) / (2 * dx);
    }
    else
    {
        return (*(u + i + 1) - *(u + i - 1)) / (2 * dx);
    }
}