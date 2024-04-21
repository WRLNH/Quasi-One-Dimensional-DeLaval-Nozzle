#include "..\include\initialize.h"
#include <iostream>

int main()
{
    int N;

    std::cout << "Input the number of nodes: ";
    std::cin >> N;

    double x[N], A[N], rho[N], T[N], V[N], t;

    initialize(x, A, rho, T, V, N);

    std::cout << " x        A         rho         T          V" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    for (int i = 0; i < N; i++)
    {
        printf("%.1lf    %.5lf    %.5lf    %.5lf    %.5lf\n", x[i], A[i], rho[i], V[i], T[i]);
    }

    return 0;
}