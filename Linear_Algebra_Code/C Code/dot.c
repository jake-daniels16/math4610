#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dot_product(int n, double x[n], double y[n]);

double dot_product(int n, double x[n], double y[n])
{
    int i;
    double dot = 0.0;
    for (i = 0; i < n; i++)
    {
        dot += x[i] * y[i];
    }
    return dot;
}