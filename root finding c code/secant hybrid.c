#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secantHybrid();
double fval(double);

int main()
{
    double a = -0.5;
    double b = 0.8;
    double tol = 0.00000001;
    double maxIter = 25;
    double rootval = secantHybrid(fval, a, b, tol, maxIter);
}

double secantHybrid(double (*f)(), double a, double b, double tol, double maxIter)
{
    double x0 = a;
    double x1 = b;
    double error = 10.0 * tol;
    double iter = 0.0;
    double f0 = f(x0);
    double f1 = f(x1);
    while(error > tol && iter < maxIter)
    {
        double x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        double secError = fabs(x2 - x1);
        if(secError > error)
        {
            double fa = f0;
            double fb = f1;
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
            x0 = a;
            x1 = b;
        } else {
            x0 = x1;
            x1 = x2;
            f0 = f1;
            f1 = f(x2);
            error = secError;
            iter = iter + 1.0;
        }
    }
    printf("\n root value = %f\n", x1);
    return x1;
}

double fval(double xval)
{
    double fval = xval * exp( - xval );
    return fval;
}
