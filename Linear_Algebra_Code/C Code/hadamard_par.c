#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8

void hadamard_par();

void hadamard_par(int n, double A[n], double b[n], double C[n])
{
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i, id, nthreads;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        for (i = id; i < n; i = i + nthreads)
        {
            C[i] = A[i] * b[i];
        }
    }
}