#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simpsons();
double fval(double);

double simpsons(double (*f)(), double a, double b, double n)
{
    double h, sum, x;
    int i;

    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }
    sum = sum * h / 3;
    return sum;
}