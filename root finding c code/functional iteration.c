#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double functionalIteration();
double fval(double);

int main()
{
    double x0 = 0.5;
    double tol = 0.00001;
    double maxIter = 25.0;
    double rootval = functionalIteration(fval, x0, tol, maxIter);
}

double functionalIteration(double (*f)(), double x0, double tol, double maxIter)
{
    double error = 10.0 * tol;
    double iter = 0.0;
    while(iter < maxIter && error > tol)
    {
        double x1 = x0 - f(x0);
        error = fabs(x1 - x0);
        x0 = x1;
        iter = iter + 1.0;
    }
    printf("\n root value = %f\n", x0);
    return x0;
}

double fval(double xval)
{
    double fval = xval * exp( - xval );
    return fval;
}

