#ifndef _CONTROL_H_
#define _CONTROL_H_
void calParRhoParTime_Predict(double *parRhoParTime_Predict, double *rho, double *V, double *A, double dx, int i);
void calParVParTime_Predict(double *parVParTime_Predict, double *V, double *T, double *rho, double dx, double gamma,
                            int i);
void calParTParTime_Predict(double *parTParTime_Predict, double *T, double *V, double *A, double dx, double gamma,
                            int i);
#endif