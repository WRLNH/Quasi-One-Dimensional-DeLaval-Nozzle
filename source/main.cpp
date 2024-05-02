#include "..\include\control.h"
#include "..\include\initialize.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

struct _nozzelParameters
{
    int nodes;
    double x[1024];
    double dx;
    double A[1024];
};

struct _flowFieldParameters
{
    double Norm[1024];
    double Bar[1024];
};

struct _parXParTime
{
    double Predictor[1024];
    double Corrector[1024];
    double Average[1024];
};

struct _time
{
    double t;
    double dt[1024];
    double timeStep;
};

struct _constants
{
    double courant;
    double gamma;
};

int main()
{
    _nozzelParameters nozzelParameter;
    _flowFieldParameters rho, V, T, P, Ma;
    _parXParTime parRhoParTime, parVParTime, parTParTime;
    _time time;
    _constants constants;

    std::cout << "Input the number of nodes: ";
    std::cin >> nozzelParameter.nodes;

    time.t = 0;
    constants.courant = 0.5;
    constants.gamma = 1.4;
    initialize(nozzelParameter.x, nozzelParameter.A, rho.Norm, V.Norm, T.Norm, nozzelParameter.nodes);
    nozzelParameter.dx = nozzelParameter.x[1] - nozzelParameter.x[0];

    for (int j = 0; j < 1500; j++)
    {
        // Predictor
        for (int i = 1; i < nozzelParameter.nodes - 1; i++)
        {
            calParRhoParTime_Predictor(parRhoParTime.Predictor, rho.Norm, V.Norm, nozzelParameter.A, nozzelParameter.dx,
                                       i);
            calParVParTime_Predictor(parVParTime.Predictor, V.Norm, T.Norm, rho.Norm, nozzelParameter.dx,
                                     constants.gamma, i);
            calParTParTime_Predictor(parTParTime.Predictor, T.Norm, V.Norm, nozzelParameter.A, nozzelParameter.dx,
                                     constants.gamma, i);
        }

        // Calculate time step
        for (int i = 1; i < nozzelParameter.nodes - 1; i++)
        {
            time.dt[i - 1] = constants.courant * nozzelParameter.dx / (V.Norm[i] + sqrt(T.Norm[i]));
        }
        time.timeStep = *std::min_element(time.dt, time.dt + nozzelParameter.nodes - 2);
        time.t += time.timeStep;

        for (int i = 0; i < nozzelParameter.nodes; i++)
        {
            rho.Bar[i] = rho.Norm[i] + parRhoParTime.Predictor[i] * time.timeStep;
            V.Bar[i] = V.Norm[i] + parVParTime.Predictor[i] * time.timeStep;
            T.Bar[i] = T.Norm[i] + parTParTime.Predictor[i] * time.timeStep;
        }

        // Corrector
        for (int i = 1; i < nozzelParameter.nodes - 1; i++)
        {
            calParRhoParTime_Corrector(parRhoParTime.Corrector, rho.Bar, V.Bar, nozzelParameter.A, nozzelParameter.dx,
                                       i);
            calParVParTime_Corrector(parVParTime.Corrector, V.Bar, T.Bar, rho.Bar, nozzelParameter.dx, constants.gamma,
                                     i);
            calParTParTime_Corrector(parTParTime.Corrector, T.Bar, V.Bar, nozzelParameter.A, nozzelParameter.dx,
                                     constants.gamma, i);
        }

        // Average
        for (int i = 0; i < nozzelParameter.nodes; i++)
        {
            parRhoParTime.Average[i] = (parRhoParTime.Predictor[i] + parRhoParTime.Corrector[i]) / 2;
            parVParTime.Average[i] = (parVParTime.Predictor[i] + parVParTime.Corrector[i]) / 2;
            parTParTime.Average[i] = (parTParTime.Predictor[i] + parTParTime.Corrector[i]) / 2;
        }

        for (int i = 1; i < nozzelParameter.nodes - 1; i++)
        {
            rho.Norm[i] += parRhoParTime.Average[i] * time.timeStep;
            V.Norm[i] += parVParTime.Average[i] * time.timeStep;
            T.Norm[i] += parTParTime.Average[i] * time.timeStep;
        }
        V.Norm[0] = 2 * V.Norm[1] - V.Norm[2];
        rho.Norm[nozzelParameter.nodes - 1] =
            2 * rho.Norm[nozzelParameter.nodes - 2] - rho.Norm[nozzelParameter.nodes - 3];
        V.Norm[nozzelParameter.nodes - 1] = 2 * V.Norm[nozzelParameter.nodes - 2] - V.Norm[nozzelParameter.nodes - 3];
        T.Norm[nozzelParameter.nodes - 1] = 2 * T.Norm[nozzelParameter.nodes - 2] - T.Norm[nozzelParameter.nodes - 3];
        for (int i = 0; i < nozzelParameter.nodes; i++)
        {
            P.Norm[i] = rho.Norm[i] * T.Norm[i];
            Ma.Norm[i] = V.Norm[i] / sqrt(T.Norm[i]);
        }
    }

    std::cout << "   x          A         rho         V          T          P         Ma" << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < nozzelParameter.nodes; i++)
    {
        printf("%.5lf    %.5lf    %.5lf    %.5lf    %.5lf    %.5lf    %.5lf\n", nozzelParameter.x[i],
               nozzelParameter.A[i], rho.Norm[i], V.Norm[i], T.Norm[i], P.Norm[i], Ma.Norm[i]);
    }
    std::cout << "At throat: rho * V * A = " << rho.Norm[15] * V.Norm[15] * nozzelParameter.A[15] << std::endl;
    std::cout << "Time: " << time.t << "s" << std::endl;

    return 0;
}
