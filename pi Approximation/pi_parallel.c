#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define NUM_THREADS 8
static long num_steps = 100000;

void main()
{
    double start, end, runTime;
    start = omp_get_wtime();
    int i, nthreads; double pi, sum[NUM_THREADS];
    double step = 2.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0) nthreads = nthrds;
        for (i=id, sum[id]=0.0;i< num_steps; i=i+nthrds)
        {
            x = -1.0 + (i+0.5)*step;
            sum[id] += 2.0*sqrt(1.0-x*x);
        }
    }
    for(i=0, pi=0.0;i<nthreads;i++)
        pi += sum[i] * step;
    end = omp_get_wtime();
    runTime = end - start;
    printf("\npi = %.20f", pi);
    printf("\nTime to run: %.10f", runTime);
}