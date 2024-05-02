#ifndef _CONTROL_H_
#define _CONTROL_H_
void calParRhoParTime_Predictor(double *parRhoParTime, double *rho, double *V, double *A, double dx, int i);
void calParVParTime_Predictor(double *parVParTime, double *V, double *T, double *rho, double dx, double gamma, int i);
void calParTParTime_Predictor(double *parTParTime, double *T, double *V, double *A, double dx, double gamma, int i);
void calParRhoParTime_Corrector(double *parRhoParTime, double *rhoBar, double *VBar, double *A, double dx, int i);
void calParVParTime_Corrector(double *parVParTime, double *VBar, double *TBar, double *rhoBar, double dx, double gamma,
                              int i);
void calParTParTime_Corrector(double *parTParTime, double *TBar, double *VBar, double *A, double dx, double gamma,
                              int i);
#endif
