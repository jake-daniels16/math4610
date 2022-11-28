#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);

void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        y[i] = 0.0;
        for (j = 0; j < n; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}