#include "..\include\control.h"
#include <cmath>

void calParRhoParTime_Predictor(double *parRhoParTime, double *rho, double *V, double *A, double dx, int i)
{
    *(parRhoParTime + i) = -(*(V + i)) * (*(rho + i + 1) - *(rho + i)) / dx -
                           *(rho + i) * (*(V + i + 1) - *(V + i)) / dx -
                           *(rho + i) * (*(V + i)) * (log(*(A + i + 1)) - log(*(A + i))) / dx;
}

void calParVParTime_Predictor(double *parVParTime, double *V, double *T, double *rho, double dx, double gamma, int i)
{
    *(parVParTime + i) =
        -(*(V + i)) * (*(V + i + 1) - *(V + i)) / dx -
        ((*(T + i + 1) - *(T + i)) / dx + (*(T + i) * (*(rho + i + 1) - *(rho + i))) / (*(rho + i) * dx)) / gamma;
}

void calParTParTime_Predictor(double *parTParTime, double *T, double *V, double *A, double dx, double gamma, int i)
{
    *(parTParTime + i) = -(*(V + i)) * (*(T + i + 1) - *(T + i)) / dx -
                         (gamma - 1) * (*(T + i)) *
                             ((*(V + i + 1) - *(V + i)) / dx + *(V + i) * (log(*(A + i + 1)) - log(*(A + i))) / dx);
}

void calParRhoParTime_Corrector(double *parRhoParTime, double *rho, double *V, double *A, double dx, int i)
{
    *(parRhoParTime + i) = -(*(V + i)) * (*(rho + i) - *(rho + i - 1)) / dx -
                           *(rho + i) * (*(V + i) - *(V + i - 1)) / dx -
                           *(rho + i) * (*(V + i)) * (log(*(A + i)) - log(*(A + i - 1))) / dx;
}

void calParVParTime_Corrector(double *parVParTime, double *V, double *T, double *rho, double dx, double gamma, int i)
{
    *(parVParTime + i) =
        -(*(V + i)) * (*(V + i) - *(V + i - 1)) / dx -
        ((*(T + i) - *(T + i - 1)) / dx + (*(T + i) * (*(rho + i) - *(rho + i - 1))) / (*(rho + i) * dx)) / gamma;
}

void calParTParTime_Corrector(double *parTParTime, double *T, double *V, double *A, double dx, double gamma, int i)
{
    *(parTParTime + i) = -(*(V + i)) * (*(T + i) - *(T + i - 1)) / dx -
                         (gamma - 1) * (*(T + i)) *
                             ((*(V + i) - *(V + i - 1)) / dx + *(V + i) * (log(*(A + i)) - log(*(A + i - 1))) / dx);
}
