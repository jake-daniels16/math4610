#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secantHybrid();
double fval(double);

double secantHybrid(double (*f)(), double a, double b, double tol, double maxIter)
{
    double x0 = a;
    double x1 = b;
    double error = fabs(b-a);
    double iter = 0.0;
    double f0 = f(x0);
    double f1 = f(x1);
    while(error > tol && iter < maxIter)
    {
        double x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0));
        double secError = fabs(x2 - x1);
        double f2 = f(x2);
        double pos = f2 * f1;
        if(secError > error && pos < 0.0)
        {
            a = x1;
            b = x2;
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
                } if(fb*fc < 0.0) {
                    a = c;
                    fa = fc;
                } else {
                    pos = 1.0;
                }
            }
            error = fabs(b - a);
            iter = iter + 1.0;
            x0 = a;
            x1 = b;
            f0 = fa;
            f1 = fb;
        } else {
            x0 = x1;
            x1 = x2;
            f0 = f1;
            f1 = f(x1);
            error = secError;
            iter = iter + 1.0;
        }
    }
    return x1;
}
