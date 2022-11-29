#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8

void matMult_par();

void matMult_par(int n, int m, int k, double A[n][m], double B[m][k], double C[n][k])
{
    for (int l = 0; l < n; l++)
    {
        for (int d = 0; d < k; d++)
        {
            C[l][d] = 0;
        }
    }
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i, j, h, id, nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        for (i = id; i < n; i += nthrds)
        {
            for (j = 0; j < k; j++)
            {
                for (h = 0; h < m; h++)
                {
                    C[i][j] += A[i][h] * B[h][j];
                }
            }
        }
    }
}