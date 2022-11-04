**Module Name:** absolute_error.c

**Author:** Jake Daniels

**Language:** C

**Description/Purpose:** This function will take an approx and an exact value and return the absolute error

**Input:** u = exact value and v = approximation

**Output:** |u-v|

**Usage/Example:** Let u = 2 be the exact value of the f'(0) where f(x)=2x, and let v=1.99 an approximation.
This will return |u-v|=.01

**Implementation/Code:** The following is code for absolute_error.c:

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
   
    double absoluteError();

    double absoluteError(double approx, double exact)
    {
        \\ Compute the absolute value of the difference
        double absError = fabs(approx - exact);
        
        \\ Return the error
        return absError;
    }
