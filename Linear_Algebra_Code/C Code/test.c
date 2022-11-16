#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* matMult();

void main()
{
    double* A[3][3];
    double* B[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A[i][j] = i;
            B[i][j] = j;
        }
    }
    double* C[3][3];
    C[3][3] = matMult(3, 3, 3, A[3][3], B[3][3]);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
}