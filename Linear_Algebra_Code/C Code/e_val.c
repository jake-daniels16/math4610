#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void e_val(int n, int part, double lambdas[part], double A[n][n], double x[n], double lambda, double tol, int max_iter);
double shifted_inv_pm(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double inv_pm(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double power_method(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);
void jacobi_iter(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);

void e_val(int n, int part, double lambdas[part + 2], double A[n][n], double x[n], double lambda, double tol, int max_iter)
{
    double ones[n], reset[n][n];
    reset[n][n] = A[n][n];
    for (int i = 0; i < n; i++)
    {
        ones[i] = 1.0;
    }
    double lambda_max = power_method(n, A, x, lambda, tol, max_iter);
    x[n] = ones[n];
    double lambda_min = inv_pm(n, A, x, lambda, tol, max_iter);
    x[n] = ones[n];
    lambdas[0] = lambda_max;
    lambdas[part + 1] = lambda_min;
    double partition = (lambda_max - lambda_min) / part;
    lambda = lambda_min + partition;
    for (int i = 1; i < part + 1; i++)
    {
        lambdas[i] = shifted_inv_pm(n, A, x, lambda, tol, max_iter);
        lambda = lambda_min + partition * (i + 1);
        x[n] = ones[n];
        A[n][n] = reset[n][n];
    }
}