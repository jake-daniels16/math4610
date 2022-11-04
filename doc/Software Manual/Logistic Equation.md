**Module Name:** logisticEqn.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** Creates a logistic equation based on a given alpha, beta and p0 values so that I
can approximate the solution using implicit and explicit euler method and compare them to the exact solution.

**Input:** alpha, beta, initial p0=p(0)

**Output:** The function will return 6 vectors, a t and x vector for each approximation.

**Usage/Example:** I wrote the following code to test this code:

    tApprox1, xApprox1, tApprox2, xApprox2, tApprox3, xApprox3 = logisticEquation(0.2, 0.0005, 10.0)
    plt.plot(tApprox1, xApprox1, color='red')
    plt.plot(tApprox2, xApprox2, color='blue')
    plt.plot(tApprox3, xApprox3, color='green')
    plt.xlabel('t')
    plt.ylabel('P(t)')
    plt.show()

Which returns the graphs given in Task 3 of Tasksheet 5.

**Implementation/Code:** The following is code for logisticEqn.py:

    # Import the necessary modules to get our approximations
    import numpy as np
    import matplotlib.pyplot as plt
    from Methods.explicitEuler import explicitEuler
    from Methods.implicitEuler import implicitEuler

    # Here is the code to approximate the ODE's for some given alpha, beta, and p0
    def logisticEquation(a, b, p0):

        # This is defining the logsitic equation
        p = lambda t, x: a * x - b * x * x

        # This is defining the derivative of the logistic equation
        dp = lambda t, x: a - 2 * b * x

        # Here we calculate the three approximations
        tval1, pval1 = explicitEuler(p, p0, 0, 10, 100)
        tval2, pval2 = implicitEuler(p, dp, p0, 0, 10, 100)
        tval3, pval3 = exactLogistic(a, b, p0, 10, 100)

        # Return all t and p values
        return tval1, pval1, tval2, pval2, tval3, pval3

    # Here is the exact calculation
    def exactLogistic(a, b, p0, T, n):

        # Starting at t0=0 and going to some point T, this h defines what step size we take to get there
        h = T / n

        # Initializing t and p vectors and appending them
        tval = []
        pval = []
        t0 = 0
        tval.append(t0)
        pval.append(p0)

        # Loop over full interval
        for i in range(1, n):

            # Change our t0 value
            t1 = t0 + h

            # Calculate the exact value
            p1 = (a * p0 * np.exp(a * t1)) / (a + b * p0 * (np.exp(a * t1) - 1))

            # Append both
            tval.append(t1)
            pval.append(p1)

            # Reassign our variables to continue the loop
            t0 = t1

        # Return necessary vectors
        return tval, pval
