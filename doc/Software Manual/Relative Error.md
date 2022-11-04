**Module Name:** relative_error.c

**Author:** Jake Daniels

**Language:** C

**Description/Purpose:** This function will take an approximation and an exact value and return the relative error

**Input:** approximation and exact value

**Output:** |approx - exact|/|exact|

**Usage/Example:** Let approx = 999 and exact = 1000, then the code returns .001.

**Implementation/Code:** The following is code for relative_error.c:

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    double relativeError();

    double relativeError(double approx, double exact)
    {
        \\ compute the error
        double relError = fabs(approx - exact) / exact;
        
        \\ return said error
        return relError;
    }
