#include "..\include\control.h"
#include "..\include\initialize.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

struct parXParTime
{
    double Predictor[1000];
    double Corrector[1000];
    double Average[1000];
};

int main()
{
    int N;

    std::cout << "Input the number of nodes: ";
    std::cin >> N;

    double x[N], A[N];
    double rho[N], V[N], T[N], P[N], Ma[N];
    double rhoBar[N], VBar[N], TBar[N];
    parXParTime parRhoParTime, parVParTime, parTParTime;
    double dt[N - 2], timeStep;
    double t = 0;
    double C = 0.5;
    double gamma = 1.4;
    initialize(x, A, rho, V, T, N);
    double dx = x[1] - x[0];

    for (int j = 0; j < 1500; j++)
    {
        // Predictor
        for (int i = 1; i < N - 1; i++)
        {
            calParRhoParTime_Predictor(parRhoParTime.Predictor, rho, V, A, dx, i);
            calParVParTime_Predictor(parVParTime.Predictor, V, T, rho, dx, gamma, i);
            calParTParTime_Predictor(parTParTime.Predictor, T, V, A, dx, gamma, i);
        }

        // Calculate time step
        for (int i = 1; i < N - 1; i++)
        {
            dt[i - 1] = C * dx / (V[i] + sqrt(T[i]));
        }
        timeStep = *std::min_element(dt, dt + N - 2);
        t += timeStep;

        for (int i = 0; i < N; i++)
        {
            rhoBar[i] = rho[i] + parRhoParTime.Predictor[i] * timeStep;
            VBar[i] = V[i] + parVParTime.Predictor[i] * timeStep;
            TBar[i] = T[i] + parTParTime.Predictor[i] * timeStep;
        }

        // Corrector
        for (int i = 1; i < N - 1; i++)
        {
            calParRhoParTime_Corrector(parRhoParTime.Corrector, rhoBar, VBar, A, dx, i);
            calParVParTime_Corrector(parVParTime.Corrector, VBar, TBar, rhoBar, dx, gamma, i);
            calParTParTime_Corrector(parTParTime.Corrector, TBar, VBar, A, dx, gamma, i);
        }

        // Average
        for (int i = 0; i < N; i++)
        {
            parRhoParTime.Average[i] = (parRhoParTime.Predictor[i] + parRhoParTime.Corrector[i]) / 2;
            parVParTime.Average[i] = (parVParTime.Predictor[i] + parVParTime.Corrector[i]) / 2;
            parTParTime.Average[i] = (parTParTime.Predictor[i] + parTParTime.Corrector[i]) / 2;
        }

        for (int i = 1; i < N - 1; i++)
        {
            rho[i] += parRhoParTime.Average[i] * timeStep;
            V[i] += parVParTime.Average[i] * timeStep;
            T[i] += parTParTime.Average[i] * timeStep;
        }
        V[0] = 2 * V[1] - V[2];
        rho[N - 1] = 2 * rho[N - 2] - rho[N - 3];
        V[N - 1] = 2 * V[N - 2] - V[N - 3];
        T[N - 1] = 2 * T[N - 2] - T[N - 3];
        for (int i = 0; i < N; i++)
        {
            P[i] = rho[i] * T[i];
            Ma[i] = V[i] / sqrt(T[i]);
        }
    }

    std::cout << "   x          A         rho         V          T          P         Ma" << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < N; i++)
    {
        printf("%.5lf    %.5lf    %.5lf    %.5lf    %.5lf    %.5lf    %.5lf\n", x[i], A[i], rho[i], V[i], T[i], P[i],
               Ma[i]);
    }
    std::cout << "At throat: rho * V * A = " << rho[15] * V[15] * A[15] << std::endl;
    std::cout << "Time: " << t << "s" << std::endl;

    return 0;
}
