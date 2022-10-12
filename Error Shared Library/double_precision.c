#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double doublePrecision();

double doublePrecision()
{
    double one = 1.0;
    double eps = 1.0;
    for(int i = 1.0; i < 101; i++)
    {
        double diff = one - (one + eps);
        if(diff == 0.0)
        {
            return eps;
        } else {
            eps = 0.5 * eps;
        }
    }
}

int main()
{
    double precision = doublePrecision();
    printf("double precision: %f\n", precision);
}
