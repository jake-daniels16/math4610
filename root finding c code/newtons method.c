#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newtonsMethod();
double fval(double);
double fpval(double);

int main()
{
    double x0 = 0.5;
    double tol = .00000001;
    double maxIter = 25;
    double rootval = newtonsMethod(fval, fpval, x0, tol, maxIter);
}

double newtonsMethod(double (*f)(), double (*fp)(), double x0, double tol, double maxIter)
{
    double error = 10.0 * tol;
    double iter = 0.0;
    while(error > tol && iter < maxIter)
    {
        double f0 = f(x0);
        double fp0 = fp(x0);
        double x1 = x0 - f0 / fp0;
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

double fpval(double xval)
{
    double fpval = exp( - xval ) - xval * exp( - xval );
    return fpval;
}

