#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float singlePrecision();

float singlePrecision()
{
    float one = 1.0f;
    float seps = 1.0f;
    float appone = 1.0f;
    double count = 0.0;
    for(int i = 1.0; i < 101; i++)
    {
        appone = one + seps;
        if(fabs(appone - one) == 0.0f)
        {
            count = count + 1.0;
            printf("loops: %f\n", count);
            printf("single precision machine epsilon = %f", seps);
            break;
        } else {
            seps = 0.5f * seps;
            count = count + 1.0;
        }
    }
}

int main()
{
    singlePrecision();
}
