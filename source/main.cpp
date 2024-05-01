#include "..\include\initialize.h"
#include <iostream>

int main()
{
    int N;

    std::cout << "Input the number of nodes: ";
    std::cin >> N;

    double x[N], A[N];
    double rho[N], V[N], T[N];
    double parRhoParTime_pre[N], parVParTime_pre[N], parTParTime_pre[N];
    double parRhoParTime_cor[N], parVParTime_cor[N], parTParTime_cor[N];
    double t = 0;
    double C = 0.5;
    double gamma = 1.4;
    initialize(x, A, rho, V, T, N);
    double dx = x[1] - x[0];

    std::cout << " x        A         rho         V          T" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    for (int i = 0; i < N; i++)
    {
        printf("%.1lf    %.5lf    %.5lf    %.5lf    %.5lf\n", x[i], A[i], rho[i], V[i], T[i]);
    }

    return 0;
}