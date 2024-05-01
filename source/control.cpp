#include "..\include\control.h"
#include <cmath>

void calParRhoParTime_Predictor(double *parRhoParTime_Predictor, double *rho, double *V, double *A, double dx, int i)
{
    *(parRhoParTime_Predictor + i) = -(*(V + i)) * (*(rho + i + 1) - *(rho + i)) / dx -
                                     *(rho + i) * (*(V + i + 1) - *(V + i)) / dx -
                                     *(rho + i) * (*(V + i)) * (log(*(A + i + 1)) - log(*(A + i))) / dx;
}

void calParVParTime_Predictor(double *parVParTime_Predictor, double *V, double *T, double *rho, double dx, double gamma,
                              int i)
{
    *(parVParTime_Predictor + i) =
        -(*(V + i)) * (*(V + i + 1) - *(V + i)) / dx -
        ((*(T + i + 1) - *(T + i)) / dx + (*(T + i) * (*(rho + i + 1) - *(rho + i))) / (*(rho + i) * dx)) / gamma;
}

void calParTParTime_Predictor(double *parTParTime_Predictor, double *T, double *V, double *A, double dx, double gamma,
                              int i)
{
    *(parTParTime_Predictor + i) =
        -(*(V + i)) * (*(T + i + 1) - *(T + i)) / dx -
        (gamma - 1) * (*(T + i)) *
            ((*(V + i + 1) - *(V + i)) / dx + *(V + i) * (log(*(A + i + 1)) - log(*(A + i))) / dx);
}

void calParRhoParTime_Corrector(double *parRhoParTime_Corrector, double *rhoBar, double *VBar, double *A, double dx,
                                int i)
{
    *(parRhoParTime_Corrector + i) = -(*(VBar + i)) * (*(rhoBar + i) - *(rhoBar + i - 1)) / dx -
                                     *(rhoBar + i) * (*(VBar + i) - *(VBar + i - 1)) / dx -
                                     *(rhoBar + i) * (*(VBar + i)) * (log(*(A + i)) - log(*(A + i - 1))) / dx;
}

void calParVParTime_Corrector(double *parVParTime_Corrector, double *VBar, double *TBar, double *rhoBar, double dx,
                              double gamma, int i)
{
    *(parVParTime_Corrector + i) = -(*(VBar + i)) * (*(VBar + i) - *(VBar + i - 1)) / dx -
                                   ((*(TBar + i) - *(TBar + i - 1)) / dx +
                                    (*(TBar + i) * (*(rhoBar + i) - *(rhoBar + i - 1))) / (*(rhoBar + i) * dx)) /
                                       gamma;
}

void calParTParTime_Corrector(double *parTParTime_Corrector, double *TBar, double *VBar, double *A, double dx,
                              double gamma, int i)
{
    *(parTParTime_Corrector + i) =
        -(*(VBar + i)) * (*(TBar + i) - *(TBar + i - 1)) / dx -
        (gamma - 1) * (*(TBar + i)) *
            ((*(VBar + i) - *(VBar + i - 1)) / dx + *(VBar + i) * (log(*(A + i)) - log(*(A + i - 1))) / dx);
}
