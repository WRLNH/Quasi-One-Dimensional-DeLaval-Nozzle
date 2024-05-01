#include "..\include\initialize.h"
#include <cmath>

void initialize(double *x, double *A, double *rho, double *V, double *T, int N)
{
    for (int i = 0; i < N; i++)
    {
        *(x + i) = 0 + 3.0 / 30 * i;
    }
    for (int i = 0; i < N; i++)
    {
        *(A + i) = 1 + 2.2 * pow((x[i] - 1.5), 2);
        *(rho + i) = 1 - 0.3146 * x[i];
        *(T + i) = 1 - 0.2314 * x[i];
        *(V + i) = (0.1 + 1.09 * x[i]) * pow(T[i], 0.5);
    }
}