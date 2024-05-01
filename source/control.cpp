#include "..\include\control.h"
#include <cmath>

void calParRhoParTime_Predict(double *parRhoParTime_Predict, double *rho, double *V, double *A, double dx, int i)
{
    *(parRhoParTime_Predict + i) = -(*(V + i)) * (*(rho + i + 1) - *(rho + i)) / dx -
                                   *(rho + i) * (*(V + i + 1) - *(V + i)) / dx -
                                   *(rho + i) * (*(V + i)) * (log(*(A + i + 1)) - log(*(A + i))) / dx;
}

void calParVParTime_Predict(double *parVParTime_Predict, double *V, double *T, double *rho, double dx, double gamma,
                            int i)
{
    *(parVParTime_Predict + i) =
        *(V + i) * (*(V + i + 1) - *(V + i)) / dx -
        ((*(V + i + 1) - *(V + i)) / dx + (*(T + i) * (*(rho + i + 1) - *(rho + i))) / (*(rho + i) * dx)) / gamma;
}

void calParTParTime_Predict(double *parTParTime_Predict, double *T, double *V, double *A, double dx, double gamma,
                            int i)
{
    *(parTParTime_Predict + i) =
        -(*(V + i)) * (*(T + i + 1) - *(T + i)) / dx -
        (gamma - 1) * (*(T + i)) *
            ((*(V + i + 1) - *(V + i)) / dx + *(V + i) * (log(*(A + i + 1)) - log(*(A + i))) / dx);
}