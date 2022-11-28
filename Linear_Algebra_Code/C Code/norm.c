#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double vector_norm(int n, double x[n]);

double vector_norm(int n, double x[n])
{
    int i;
    double norm = 0.0;
    for (i = 0; i < n; i++)
    {
        norm += x[i] * x[i];
    }
    return sqrt(norm);
}