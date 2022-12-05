#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double shifted_inv_pm_GS(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);
void gauss_seidel(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);

double shifted_inv_pm_GS(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter)
{
    double error = 10.0 * tol;
    double y[n], w[n], z[n];
    int iter = 0;
    double shift = lambda;
    for (int i = 0; i < n; i++)
    {
        A[i][i] = A[i][i] - lambda;
    }
    gauss_seidel(n, A, y, x, tol, max_iter);
    while (error > tol && iter < max_iter)
    {
        vecScalar(n, 1 / vector_norm(n,y), y, z);
        gauss_seidel(n, A, w, z, tol, max_iter);
        double lambda_new = dot_product(n, z, w);
        error = fabs(lambda_new - lambda);
        lambda = lambda_new;
        vecScalar(n, 1 / vector_norm(n, w), w, y);
        iter++;
    }
    return 1 / lambda + shift;
}