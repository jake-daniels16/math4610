#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8

void mv_par(int n, double A[n][n], double x[n], double y[n]);

void mv_par(int n, double A[n][n], double x[n], double y[n])
{
    for (int i = 0; i < n; i++)
    {
        y[i] = 0.0;
    }
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i, j, id, nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        for (i = 0; i < n; i++)
        {
            for (j = id; j < n; j = j + nthrds)
            {
                y[i] += A[i][j] * x[j];
            }
        }
    }
}