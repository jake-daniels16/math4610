#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void outerProduct_vec();

void outerProduct_vec(int n, int m, double A[n], double B[m], double C[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            C[i][j] = A[i] * B[j];
        }
    }
}