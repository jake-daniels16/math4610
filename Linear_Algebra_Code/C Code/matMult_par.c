#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8

void matMult_par();

void matMult_par(int n, int m, int k, double A[n][m], double B[m][k], double C[n][k])
{
    int h, i, j, nthrds, id;
    for (int l = 0; l < n; l++)
    {
        for (int d = 0; d < k; d++)
        {
            C[l][d] = 0;
        }
    }
    omp_set_num_threads(NUM_THREADS);
    nthrds = omp_get_num_threads();
    #pragma omp parallel
    {
        id = omp_get_thread_num();
        for (i = 0; i < n; i++)
            {
                for (j = 0; j < k; j++)
                {   
                    for (h = id; h < m; h = h + nthrds)
                    {
                        C[i][j] += A[i][h] * B[h][j];
                    }
                }
            }
    }
}