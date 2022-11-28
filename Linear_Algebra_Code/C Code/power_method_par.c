#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double power_method_par(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
void mv_par(int n, double A[n][n], double x[n], double y[n]);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);

double power_method_par(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter)
{
    double error = 10.0 * tol;
    int iter = 0;
    double y[n], w[n], z[n];
    mv_par(n, A, x, y);
    while(error > tol && iter < max_iter)
    {
        double norm = 1 / vector_norm(n, y);
        vecScalar(n, norm, y, z);
        mv_par(n, A, z, w);
        double lambda_1 = dot_product(n, z, w);
        error = fabs(lambda_1 - lambda);
        iter = iter + 1.0;
        lambda = lambda_1;
        y[n] = w[n];
    }
    return lambda;
}