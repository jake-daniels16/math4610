#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void matMult_par(int n, int m, int k, double A[n][m], double B[m][k], double C[n][k]);
void hadamard(int n, double A[n], double b[n], double C[n]);
void hadamard_par(int n, double A[n], double b[n], double C[n]);
void hadamard_mat(int n, int m, double A[n][m], double B[n][m], double C[n][m]);
void outerProduct_vec(int n, int m, double A[n], double B[m], double C[n][m]);

void main() //task 1
{
    double A[3][3], B[3][3], C[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A[i][j] = i + 1.0;
            B[i][j] = j + 1.0;
        }
    }
    matMult_par(3, 3, 3, A, B, C);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
}

//void main() //task 2
//{
//    double A[3] = {1, 2, 3};
//    double b[3] = {3, 2, 1};
//    double C[3];
//    hadamard(3, A, b, C);
//    for (int i = 0; i < 3; i++)
//    {
//        printf("%f ", C[i]);
//    }
//}

//void main() //task 3
//{
//    double A[3] = {1, 2, 3};
//    double b[3] = {3, 2, 1};
//    double C[3];
//    hadamard_par(3, A, b, C);
//    for (int i = 0; i < 3; i++)
//    {
//        printf("%f ", C[i]);
//    }
//}

//void main() //task 4
//{
//    double A[10][10], B[10][10], C[10][10];
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            A[i][j] = i;
//            B[i][j] = j;
//        }
//    }
//    hadamard_mat(10, 10, A, B, C);
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            printf("%f ", C[i][j]);
//        }
//        printf("\n");
//    }
//}

//void main() //task 5
//{
//    double A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    double B[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//    double C[10][10];
//    outerProduct_vec(10, 10, A, B, C);
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            printf("%f ", C[i][j]);
//        }
//        printf("\n");
//    }
//}