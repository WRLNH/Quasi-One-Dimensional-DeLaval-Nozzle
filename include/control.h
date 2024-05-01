#ifndef _CONTROL_H_
#define _CONTROL_H_
void calParRhoParTime_Predictor(double *parRhoParTime_Predictor, double *rho, double *V, double *A, double dx, int i);
void calParVParTime_Predictor(double *parVParTime_Predictor, double *V, double *T, double *rho, double dx, double gamma,
                              int i);
void calParTParTime_Predictor(double *parTParTime_Predictor, double *T, double *V, double *A, double dx, double gamma,
                              int i);
void calParRhoParTime_Corrector(double *parRhoParTime_Corrector, double *rhoBar, double *VBar, double *A, double dx,
                                int i);
void calParVParTime_Corrector(double *parVParTime_Corrector, double *VBar, double *TBar, double *rhoBar, double dx,
                              double gamma, int i);
void calParTParTime_Corrector(double *parTParTime_Corrector, double *TBar, double *VBar, double *A, double dx,
                              double gamma, int i);
#endif
