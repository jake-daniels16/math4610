#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* hadamard();

double* hadamard(int n, double A[n], double b[n])
{
    double C[n];
    int i;
    for (i = 0; i < n; i++)
    {
        C[i] = A[i] * b[i];
    }
    return C;
}