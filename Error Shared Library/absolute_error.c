#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double absoluteError();

double absoluteError(double approx, double exact)
{
    double absError = fabs(approx - exact);
    return absError;
}
