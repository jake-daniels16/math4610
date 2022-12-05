#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void e_val(int n, int part, double lambdas[part], double A[n][n], double x[n], double lambda, double tol, int max_iter);
void e_val_par(int n, int part, double lambdas[part], double A[n][n], double x[n], double lambda, double tol, int max_iter);
double inv_pm(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double power_method(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
double vector_norm(int n, double x[n]);
double dot_product(int n, double x[n], double y[n]);
void vecScalar(int n, double a, double x[n], double y[n]);
void jacobi_iter(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);
void matrix_vector_mult(int n, double A[n][n], double x[n], double y[n]);
double shifted_inv_pm(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);
void gauss_seidel(int n, double A[n][n], double x[n], double b[n], double tol, int max_iter);
double shifted_inv_pm_GS(int n, double A[n][n], double x[n], double lambda, double tol, int max_iter);

//void main() //task 1
//{
//    int n = 3;
//    double A[n][n], x[n];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                A[i][j] = i + 4.0;
//            }
//            else
//            {
//                A[i][j] = 1;
//            }
//        }
//        x[i] = 1;
//    }   
//    int max_iter = 100;
//    double tol = 1e-6;
//    double lambda = 0.0;
//    double lambda_new = inv_pm(n, A, x, lambda, tol, max_iter);
//    printf("lambda = %f", lambda_new);
//}

//void main() //task 2
//{
//    int n = 3;
//    double A[n][n], x[n];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                A[i][j] = i + 4.0;
//            }
//            else
//            {
//                A[i][j] = 0.1;
//            }
//        }
//        x[i] = 1;
//    }
//    int max_iter = 100;
//    double tol = 1e-6;
//    double lambda = 4.8;
//    double lambda_new = shifted_inv_pm(n, A, x, lambda, tol, max_iter);
//    printf("lambda = %f", lambda_new);
//}

//void main() //task 3
//{
//    int n = 3;
//    double A[n][n], x[n];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                A[i][j] = i + 4.0;
//            }
//            else
//            {
//                A[i][j] = 0.1;
//            }
//        }
//        x[i] = 1;
//    }
//    int max_iter = 1000;
//    double tol = 1e-6;
//    double lambda = 0.0;
//    double max, min;
//    int part = n - 1;
//    double lambdas[part + 2];
//    e_val(n, part, lambdas, A, x, lambda, tol, max_iter);
//    printf("\nlambda max: %f", lambdas[0]);
//    for (int i = 1; i < part + 1; i++)
//    {
//        if (lambdas[i] > lambdas[part + 1] && lambdas[i] < lambdas[0])
//        {
//            printf("\nlambda: %f", lambdas[i]);
//        } else {
//            printf("");
//        }
//    }
//    printf("\nlambda min: %f", lambdas[part + 1]);
//}

//void main() //task 4
//{
//    int n = 3;
//    double A[n][n], x[n];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                A[i][j] = i + 4.0;
//            }
//            else
//            {
//                A[i][j] = 0.1;
//            }
//        }
//        x[i] = 1;
//    }
//    int max_iter = 1000;
//    double tol = 1e-6;
//    double lambda = 0.0;
//    double max, min;
//    int part = n - 1;
//    double lambdas[part + 2];
//    e_val_par(n, part, lambdas, A, x, lambda, tol, max_iter);
//    printf("lambda max: %f", lambdas[0]);
//    for (int i = 1; i < part + 1; i++)
//    {
//        if (lambdas[i] > lambdas[part + 1] && lambdas[i] < lambdas[0])
//        {
//            printf("\nlambda: %f", lambdas[i]);
//        } else {
//            printf("");
//        }
//    }
//    printf("\nlambda min: %f", lambdas[part + 1]);
//}

//void main() //task 5a
//{
//    int n = 3;
//    double A[n][n], x[n], b[n];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                A[i][j] = i + 4.0;
//            }
//            else
//            {
//                A[i][j] = 0.1;
//            }
//        }
//        x[i] = 1;
//        b[i] = 1;
//    }
//    int max_iter = 1000;
//    double tol = 1e-6;
//    gauss_seidel(n, A, x, b, tol, max_iter);
//    printf("x = %f, %f, %f", x[0], x[1], x[2]);
//}

void main() //task 5b
{
  int n = 3;
    double A[n][n], x[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                A[i][j] = i + 4.0;
            }
            else
            {
                A[i][j] = 0.1;
            }
        }
        x[i] = 1;
    }
    int max_iter = 100;
    double tol = 1e-6;
    double lambda = 4.8;
    double lambda_new = shifted_inv_pm_GS(n, A, x, lambda, tol, max_iter);
    printf("lambda = %f", lambda_new);
}