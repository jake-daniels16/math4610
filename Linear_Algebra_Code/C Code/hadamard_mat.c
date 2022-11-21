#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hadamard_mat();

void hadamard_mat(int n, int m, double A[n][m], double B[n][m], double C[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}