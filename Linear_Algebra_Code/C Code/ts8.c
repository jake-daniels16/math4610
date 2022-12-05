#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

void kronecker(int n, int m, int k, int l, double A[n][m], double B[k][l], double C[n*k][m*l]);
double power_method(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double re_power_method(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);
double power_method_par(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
void mv_par(int n, double A[n][n], double x[n], double y[n]);
void jacobi_iter(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);

//void main() //task 1
//{
//    int n = 5;
//    int m = 5;
//    int k = 3;
//    int l = 3;
//    double A[n][m], B[k][l], C[n*k][m*l];
//    int i, j, h, d;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            A[i][j] = i + 1.0;
//            B[i][j] = j + 1.0;
//        }
//    }
//    kronecker(n, m, k, l, A, B, C);
//    for (i = 0; i < n*k; i++)
//    {
//        for (j = 0; j < m*l; j++)
//        {
//            printf("%f ", C[i][j]);
//        }
//        printf("\n");
//    }
//}

//void main() //task 2
//{
//    int n = 5;
//    double A[n][n], x[n], y[n];
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            A[i][j] = i + 1.0;
//        }
//        x[i] = 1.0;
//    }
//    double lambda = 1.0;
//    double tol = 1e-6;
//    int max_iter = 100;
//    double lambda_2 = power_method(n, A, x, lambda, tol, max_iter);
//    printf("%f", lambda_2);
//}

void main() //task 2a
{
    int n = 10;
    double A[n][n], x[n], y[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = i + 1.0;
        }
        x[i] = 1.0;
    }
    double lambda = 0.0;
    double tol = 1e-6;
    int max_iter = 100;
    double lambda_2 = power_method(n, A, x, lambda, tol, max_iter);
    printf("%f", lambda_2);
}

//void main() //task 3 part 1
//{
//    int n = 5;
//    double A[n][n], x[n], y[n];
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            A[i][j] = i + 1.0;
//        }
//        x[i] = 1.0;
//    }
//    double lambda = 1.0;
//    double tol = 1e-6;
//    int max_iter = 100;
//    double lambda_3 = re_power_method(n, A, x, lambda, tol, max_iter);
//    printf("%f", lambda_3);
//}

// for task 3 part 2 refer to latex file, it was too long to comment out

//void main() //task 4
//{
//    int n = 5;
//    double A[n][n], x[n], y[n];
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            A[i][j] = i + 1.0;
//        }
//        x[i] = 1.0;
//    }
//    double lambda = 1.0;
//    double tol = 1e-6;
//    int max_iter = 100;
//    double lambda_4 = power_method_par(n, A, x, lambda, tol, max_iter);
//    printf("%f", lambda_4);
//}

//void main() //task 5
//{
//    int n = 100;
//    double A[n][n], b[n], x[n];
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                A[i][j] = 100.0;
//            } else {
//                A[i][j] = 1.0;
//            }
//        }
//        b[i] = 1.0;
//        x[i] = 0.0;
//    }
//    double tol = 1e-6;  
//    int max_iter = 1000;
//    jacobi_iter(n, A, x, b, tol, max_iter);
//    for (i = 0; i < n; i++)
//    {
//        printf("\n%f ", x[i]);
//    }
//}