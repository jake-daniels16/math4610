#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8

double* hadamard_par();

double* hadamard_par(int n, double A[n], double b[n])
{
    double C[n];
    #pragma omp parallel for
    {
        int i, id, nthreads;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        for (i = id; i < n; i = i + nthreads)
        {
            C[i] = A[i] * b[i];
        }
    }
    return C;
}