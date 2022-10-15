#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double doublePrecision();

double doublePrecision()
{
    double one = 1.0d;
    double deps = 1.0d;
    double appone = 1.0d;
    double count = 0.0;
    for(int i = 1.0; i < 101; i++)
    {
        appone = one + deps;
        if(fabs(appone - one) == 0.0d)
        {
            count = count + 1.0;
            printf("loops: %f\n", count);
            printf("double precision machine epsilon: %f", deps);
            break;
        } else {
            deps = deps * 0.5d;
            count = count + 1.0;
        }
    }
}

int main()
{
    doublePrecision();
}
