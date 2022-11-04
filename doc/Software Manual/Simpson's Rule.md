**Module Name:** simpsons.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** Approximate the integral using Simpson's Rule

**Input:** A function f, the values for our definite integral, a and b, lastly n, the amount of subintervals we want to split our interval a,b into

**Output:** The approximation

**Usage/Example:** I wrote this code to test it for the function exp(-x^2):

    sum= simpsons(lambda x: np.exp(- x * x), 0, np.pi / 4, 16)
    print("n = ", n, " ", sum)

Which outputted:

    sum = 0.6498804267988076

**Implementation/Code:** The following is code for simpsons.py

    import numpy as np

    def simpsons(f, a, b, n):

        # define the step size
        h = (b - a) / n

        # Add f evaluated at a and b so we don't have to account for them in the loop
        sum  = f(a) + f(b)

        # range over whole interval
        for i in range(1, n):

            # Move our x a step for each loop and evaluate f at that point
            x = a + i * h
            fx = f(x)

            # If x is even add it twice which comes directly from Simpson's Rule
            if i % 2 == 0:
                sum = sum + 2 * fx

            # If x is odd add it four times which again comes from Simpson's Rule
            else:
                sum = sum + 4 * fx

        # Multiply the sum by the common value h / 3 and return the sum
        sum = sum * h / 3
        return sum
