#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void jacobi_iter(int n, double A[n][n], double b[n], double x[n], double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);
double dot_product(int n, double x[n], double y[n]);

void jacobi_iter(int n, double A[n][n], double b[n], double x[n], double tol, int max_iter)
{
    int iter = 0;
    double error = 10.0 * tol;
    double c[n], y[n], r[n];
    matrix_vector_mult(n, A, x, c);
    for (int i = 0; i < n; i++)
    {
        r[i] = b[i] - c[i];
    }
    while (error > tol && iter < max_iter)
    {
        for (int i = 0; i < n; i++)
        {
            y[i] = x[i] + r[i] / A[i][i];
        }
        error = dot_product(n, r, r);
        if (error < tol)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            x[i] = y[i];
        }
        matrix_vector_mult(n, A, x, c);
        for (int i = 0; i < n; i++)
        {
            r[i] = b[i] - c[i];
        }
        iter++;
    }
}