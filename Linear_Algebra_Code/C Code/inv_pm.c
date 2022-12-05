#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double inv_pm(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);
void jacobi_iter(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);

double inv_pm(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter)
{
    double error = 10.0 * tol;
    double y[n], w[n], z[n];
    int iter = 0;
    jacobi_iter(n, A, y, x, tol, max_iter); //this is solving Ay=x for y
    while (error > tol && iter < max_iter)
    {
        vecScalar(n, 1 / vector_norm(n,y), y, z);
        jacobi_iter(n, A, w, z, tol, max_iter); //this is solving Aw=z for w
        double lambda_new = dot_product(n, z, w);
        error = fabs(lambda_new - lambda);
        lambda = lambda_new;
        vecScalar(n, 1 / vector_norm(n, w), w, y);
        iter++;
    }
    return 1 / lambda;
}