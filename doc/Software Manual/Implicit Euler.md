**Module Name:** implicitEuler.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take approximate the solution to an ODE using the Implicit Euler method.

**Input:** A function and its derivative, as well as an initial function value, x0, as well as the left and right endpoints
of an interval t0 and T, as well as how many times we want to divide our interval n.

**Output:** A vector for the t and x values

**Usage/Example:** I wrote the following code to use this module:

    import numpy as np
    import matplotlib.pyplot as plt
    from Methods.implicitEuler import implicitEuler

    def logisticEquation(a, b, p0):
        p = lambda t, x: a * x - b * x * x
        dp = lambda t, x: a - 2 * b * x
        tval, pval = implicitEuler(p, dp, p0, 0, 10, 100)
        return tval, pval

    tApprox1, xApprox1 = logisticEquation(0.2, 0.0005, 10.0)
    plt.plot(tApprox1, xApprox1, color='red')
    plt.xlabel('t')
    plt.ylabel('P(t)')
    plt.show()
    
This returns the graph that can be found in Tasksheet 5 Task 1.

**Implementation/Code:** The following is code for implicitEuler.py:
    
    # Import the correct modules and newtonsMethod which will be needed
    import numpy as np
    from Methods.newt import newtonsMethod

    def implicitEuler(f, df, x0, t0, T, n):
    
        # Here we are calculating how much we move the t value for each approximation
        h = (T - t0) / n
        
        # Initializing the first f value
        f0 = f(t0, x0)
        
        # Initializing the vectors for t and x and append the initial values
        tval = []
        xval = []
        tval.append(t0)
        xval.append(x0)
        
        # Loop over the whole interval given
        for i in range(1, n):
        
            # We have the first function value at t0 so now we move to t1
            t1 = t0 + h
            
            # Use newton's method to find the next x value
            x1 = newtonsMethod(lambda x: x - x0 - h * f(t1, x), lambda x: 1 - h * df(t1, x), x0, .00000001, 50, "n")
            
            # Reassign our x and t values to continue the loop and append them
            x0 = x1
            t0 = t1
            tval.append(t0)
            xval.append(x0)
            
        # return the vectors
        return tval, xval
