**Module Name:** secant.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will compute an approximation of a root for any given function using the Secant Method.

**Input:** This function will compute an approximation of a root for any given function using the secant Method. The advantage 
of using this method over Newton's method is we don't have to use the derivative to compute the approximation for our root.

**Output:** The function will return a single approximation of a root for the given function.

**Usage/Example:** We will answer the following prompts as follows for the example of f(x)=x e^{-x}:

    Enter function you want to find the roots for (in terms of x): x*np.exp(-x)
    Input initial guesses for root here as (x0, x1): -1, 1
    Input tolerance here: .00000001
    Input max number of iterations here: 25

We need to input the functions as such using the numpy module and construction of python. The following input will yield 
the following output:

    Root approximation:  1.549984207858443e-15
  
Which is approximately zero, so using this approximation we can guess that the function above has a root at or near x=0.

**Implementation/Code:** The following is code for secant.py

    # This is the module that allows us to input functions involving elementary functions like (e, sin, cos,...)
    import numpy as np

    # This is the function that will be used to ask the user for the function
    def fn():
        f = input("Enter function you want to find the roots for (in terms of x): ")
        return f

    # This is the function that will compute a function, at a value, x
    def f(fn, x):
        fval = eval(fn)
        return fval

    # This is the function that will ask the user for two initial guesses
    def initialGuesses():
        x0, x1 = eval(input("Input initial guesses for root here as (x0, x1): "))
        return x0, x1

    # This function asks the user for the tolerance wanted
    def tolerance():
        tol = eval(input("Input tolerance here: "))
        return tol

    # This function asks the user for the max number of iterations
    def maxIter():
        mI = eval(input("Input max number of iterations here: "))
        return mI

    # Asks the user if they want a table and returns their choice
    def wantTable():
        print("Do you want a table?")
        print("\t1) Yes")
        print("\t2) No")
        choice = eval(input("Enter here: "))
        return choice

    # Prints a line of the table of the three things the user wants in it
    def table(a,b,c):
        print("(1)" , a, " (2) ", b, " (3) ", c)

    # Below is the function that actually compiles all these functions to compute the approximation
    def secantMethod():
        # Below we are asking the user for everything they want
        fun = fn()
        x0, x1 = initialGuesses()
        tol = tolerance()
        mI = maxIter()

        # Here is where we now ask the user for a table
        choice = wantTable()

        # We set an iteration counter and an initial error so that we can make the following while loop
        error = 10 * tol
        iter = 0

        # By computing the values for the functions outside the loop, it will decrease the amount of things we have to do per run through of the loop
        f0 = f(fun, x0)
        f1 = f(fun, x1)

        # 1 is if they select yes
        if choice == 1:

          # This while loop will run until the error is less than the tolerance or we hit the maximum number of iterations
          while error > tol and iter < mI:

              # We compute the approximation of the root
              x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0)

              # Update error and iteration number to make sure the loop is updated to see if it needs to stop
              error = np.abs(x2 - x1)
              iter = iter + 1

              # Here we pass the iteration number, approximation, and error into the table function which prints the table
              table(iter, x2, error)

              # Update x0 as second guess x1, as well as their function values, we now compute a new function value for f1 to be the function evaluated at our approximation, this will continue the process of creating new approximations that will hopefully converge to a root
              x0 = x1
              x1 = x2
              f0 = f1
              f1 = f(fun, x2)

        # 2 is if they select no so it is same as above with a print statement returning root at bottom
        elif choice == 2:

            while error > tol and iter < mI:
                x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0)
                error = np.abs(x2 - x1)
                iter = iter + 1
                x0 = x1
                x1 = x2
                f0 = f1
                f1 = f(fun, x2)

            # Take the last approximation given once loop ends and print it for the user to see
            print("Root approximation: ", x1)
