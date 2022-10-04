#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double bisect();
double functionalIteration();
double newtonHybrid();
double newtonsMethod();
double secantHybrid();
double secantMethod();
double fval(double);
double fpval(double);

int main()
{
    double a = -0.5;
    double b = 0.8;
    double tol = .00000001;
    double maxIter = 25;
    double r1 = bisect(fval, a, b, tol, maxIter);
    double r2 = functionalIteration(fval, b, tol, maxIter);
    double r3 = newtonHybrid(fval, fpval, a, b, tol, maxIter);
    double r4 = newtonsMethod(fval, fpval, b, tol, maxIter);
    double r5 = secantMethod(fval, a, b, tol, maxIter);
    double r6 = secantHybrid(fval, a, b, tol, maxIter);
}

double bisect(double (*f)(), double a, double b, double tol)
{
    double fa = f(a);
    double fb = f(b);
    if(fa*fb >= 0.0)
    {
        printf("There may not be a root in [a,b]: f(a)*f(b) = %e", fa*fb);
        exit(-1);
    }
    double c;
    double fc;
    int k = ( (int) ( log(tol) - log(b-a) ) / log(0.5) + 1 );
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
    printf("\n bisect root value = %f\n", c);
    return c;
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
    printf("\n functional iteration root value = %f\n", x0);
    return x0;
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
    printf("\n secant method root value = %f\n", x1);
    return x1;
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
    printf("\n secant hybrid root value = %f\n", x1);
    return x1;
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
    printf("\n newtons method root value = %f\n", x0);
    return x0;
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
    printf("\n newton hybrid root value = %f\n", x0);
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
