#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double power_method(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);

double power_method(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter)
{
    double error = 10.0 * tol;
    double v[n], y[n], z[n];
    int iter = 0;
    while (error > tol && iter < max_iter)
    {
        matrix_vector_mult(n, A, x, v);
        double norm = 1 / vector_norm(n, v);
        vecScalar(n, norm, v, y);
        matrix_vector_mult(n, A, y, z);
        double lambda_1 = dot_product(n, y, z);
        x[n] = y[n];
        error = fabs(lambda_1 - lambda);
        lambda = lambda_1;
        iter = iter + 1.0;
    }
    return lambda;
}