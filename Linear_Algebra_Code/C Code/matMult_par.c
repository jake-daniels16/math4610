#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8

double* matMult();

double* matMult(int n, int m, int k, double A[n][m], double B[m][k])
{
    double C[n][k];
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int h, i, j, nthreads, id;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        #pragma omp for
        for (i = 0; i < n; i = i++)
        {
            for (j = 0; j < k; j++)
            {
                C[i][j] = 0;
                for (h = id; h < m; h = h + nthreads)
                {
                    C[i][j] += A[i][h] * B[h][j];
                }
            }
        }
    }
    return C;
}