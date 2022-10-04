#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secantMethod();
double fval(double);

int main()
{
    double x0 = -0.5;
    double x1 = 0.8;
    double tol = .00000001;
    double maxIter = 25;
    double rootval = secantMethod(fval, x0, x1, tol, maxIter);
}

double secantMethod(double (*f)(), double x0, double x1, double tol, double maxIter)
{
    double error = 10.0 * tol;
    double iter = 0.0;
    double f0 = f(x0);
    double f1 = f(x1);
    while(error > tol && iter < maxIter)
    {
        double x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        error = fabs(x2 - x1);
        x0 = x1;
        x1 = x2;
        f0 = f1;
        f1 = f(x2);
        iter = iter + 1.0;
    }
    printf("\n root value = %f\n", x1);
    return x1;
}

double fval(double xval)
{
    double fval = xval * exp( - xval );
    return fval;
}


