#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double relativeError();

double relativeError(double approx, double exact)
{
    double relError = fabs(approx - exact) / exact;
    return relError;
}
