#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fval(double);

double fval(double x)
{
    double fx;
    fx = 2 * sqrt(1 - ( x * x ));
    return fx;
}