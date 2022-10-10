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
    double tol = 0.00000001;
    double maxIter = 25.0;
    double r1 = bisect(fval, a, b, tol);
    double r2 = functionalIteration(fval, a, tol, maxIter);
    double r3 = newtonsMethod(fval, fpval, a, tol, maxIter);
    double r4 = secantMethod(fval, a, b, tol, maxIter);
    double r5 = newtonHybrid(fval, fpval, a, b, tol, maxIter);
    double r6 = secantHybrid(fval, a, b, tol, maxIter);
    printf("\n bisect root = %f\n", r1);
    printf("\n functional iteration root = %f\n", r2);
    printf("\n newtons method root = %f\n", r3);
    printf("\n secant method root = %f\n", r4);
    printf("\n newton hybrid root = %f\n", r5);
    printf("\n secant hybrid root = %f\n", r6);
}



