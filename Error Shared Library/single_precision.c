#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float singlePrecision();

float singlePrecision()
{
    float one = 1.0;
    float eps = 1.0;
    for(int i = 1.0; i < 101; i++)
    {
        float diff = one - (one + eps);
        if(diff = 0.0){
            return eps;
        } else {
            eps = 0.5 * eps;
        }
    }
}

int main()
{
    double precision = singlePrecision();
    printf("single precision %f\n", precision);
}
