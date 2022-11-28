#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void jacobi_iter(int n, double A[n][n], double b[n], double x[n], double tol, int max_iter);

void jacobi_iter(int n, double A[n][n], double b[n], double x[n], double tol, int max_iter)
{
    int i, j, k;
    double sum, error;
    double x_new[n];
    for (i = 0; i < n; i++)
    {
        x_new[i] = 0.0;
    }
    error = tol * 10.0;
    int iter = 0;
    while (error > tol && iter < max_iter)
    {
        for (i = 0; i < n; i++)
        {
            sum = 0.0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }
        for (i = 0; i < n; i++)
        {
            error += fabs(x_new[i] - x[i]);
        }
        for (i = 0; i < n; i++)
        {
            x[i] = x_new[i];
        }
        iter++;
    }
}