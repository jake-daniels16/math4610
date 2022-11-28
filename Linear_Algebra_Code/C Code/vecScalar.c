#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vecScalar(int n, double a, double x[n], double y[n]);

void vecScalar(int n, double a, double x[n], double y[n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        y[i] = a * x[i];
    }
}