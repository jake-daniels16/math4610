#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

void main()
{
    double start, end, runTime;
    start = omp_get_wtime();
    double a, b, n, pi, h, sum, x; int i;
    a = -1.0;
    b = 1.0;
    n = 100000.0;
    h = (b - a) / n;
    sum = 2.0 * sqrt(1.0 - (a * a)) + 2.0 * sqrt(1.0 - (b * b));
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 2 == 0)
            sum += 4.0 * sqrt(1.0 - (x * x));
        else
            sum += 8.0 * sqrt(1.0 - (x * x));
    }
    pi = sum * h / 3.0;
    end = omp_get_wtime();
    runTime = end - start;
    printf("\npi = %.20f", pi);
    printf("\nTime to run: %.10f", runTime);
}


