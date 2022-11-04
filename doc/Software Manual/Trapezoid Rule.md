**Module Name:** trapezoid.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** Approximate the solution to an integral using trapezoid rule

**Input:** A function f, the values for our definite integral, a and b, lastly n, the amount of subintervals
we want to split our interval a,b into

**Output:** The approximation

**Usage/Example:** I used the following code to approximate the integral of exp(-x^2):

    trapezoid(lambda x: np.exp(- x * x), 0, np.pi / 4, 16)
    print("sum = ", sum)

Which outputted the following:

    sum = 0.6497100964398593

**Implementation/Code:** The following is code for trapezoid.py

    import numpy as np

    def trapezoid(f, a, b, n):
        # calculate the step size
        h = (b - a) / n

        # We know that from the trapezoid rule we will only need to add f(a) and f(b) once so we add them
        # at the beginning divided by 2 again due to the rule
        sum = 0.5 * (f(a) + f(b))

        # Now we loop over our whole interval
        for i in range(1, n):

            # Move our x i*h to the right until we eventually span the whole interval
            x = a + i * h

            # Add the function value at the above x for each x value to the sum
            fx = f(x)
            sum = sum + fx

        # Multiply our sum by the step size h and return it
        sum = sum * h
        return sum
