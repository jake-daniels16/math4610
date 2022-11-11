#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simpsons();
double fval(double);

int main()
{
    double pi1;
    double pi2;
    double pi3;
    double pi4;
    double pi5;
    pi1 = simpsons(fval, -1.0, 1.0, 10.0);
    pi2 = simpsons(fval, -1.0, 1.0, 100.0);
    pi3 = simpsons(fval, -1.0, 1.0, 1000.0);
    pi4 = simpsons(fval, -1.0, 1.0, 10000.0);
    pi5 = simpsons(fval, -1.0, 1.0, 100000.0);
    printf("\n n = 10 | pi = %.20f", pi1);
    printf("\n n = 100 | pi = %.20f", pi2);
    printf("\n n = 1000 | pi = %.20f", pi3);
    printf("\n n = 10000 | pi = %.20f", pi4);
    printf("\n n = 100000 | pi = %.20f", pi5);
}