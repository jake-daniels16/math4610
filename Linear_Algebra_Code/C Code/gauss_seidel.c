#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss_seidel(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);

void gauss_seidel(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter)
{
    int iter = 0;
    double error = 10.0 * tol;
    double c[n], y[n], r[n];
    while (error > tol && iter < max_iter)
    {
        for (int i = 0; i < n; i++)
        {
            y[i] = b[i];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    y[i] -= A[i][j] * x[j];
                }
            }
            y[i] /= A[i][i];
        }
        error = 0.0;
        for (int i = 0; i < n; i++)
        {
            error += (y[i] - x[i]) * (y[i] - x[i]);
        }
        error = sqrt(error);
        if (error < tol)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            x[i] = y[i];
        }
        iter++;
    }
}