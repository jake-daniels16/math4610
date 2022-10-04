#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newtonHybrid();
double fval(double);
double fpval(double);

int main()
{
    double a = -0.5;
    double b = 0.8;
    double tol = .00000001;
    double maxIter = 25;
    double rootval = newtonHybrid(fval, fpval, a, b, tol, maxIter);
}

double newtonHybrid(double (*f)(), double (*fp)(), double a, double b, double tol, double maxIter)
{
    double x0 = 0.5 * (a + b);
    double error = 10.0 * tol;
    double iter = 0.0;
    while(error > tol && iter < maxIter)
    {
        double f0 = f(x0);
        double fp0 = fp(x0);
        double x1 = x0 - f0 / fp0;
        double newtError = fabs(x1 - x0);
        if(newtError > error)
        {
            double fa = f(a);
            double fb = f(b);
            double c;
            double fc;
            int k = 4.0;
            for(int i=0; i<k; i++)
            {
                c = 0.5 * ( a + b );
                fc = f(c);
                if(fa*fc < 0.0)
                {
                    b = c;
                    fb = fc;
                } else {
                    a = c;
                    fa = fc;
                }
            }
            error = fabs(b - a);
            x0 = 0.5 * (a + b);
        } else {
            x0 = x1;
            error = newtError;
            iter = iter + 1.0;
        }
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

