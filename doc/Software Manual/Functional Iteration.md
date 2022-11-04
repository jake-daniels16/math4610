**Module Name:** fnIter.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will compute an approximation of a root for any given function using functional iteration. 
The main idea is that we will take a function f and create a new function g(x)=x-f(x) where we will look where g(x)=x which
will be where f(x0)=0 which will be a root.

**Input:** The user will need to input a function, f They will also need to give an initial point x0, as well as a max number of 
iterations and a tolerance. As well as choose whether or not they want a table.

**Output:** The function will return two approximations of a root for the given function, one from g1(x) and another from g2(x).

**Usage/Example:** We will answer the following prompts as follows for the example of f (x) = x*np.exp(-x):

    Enter function you want to find the roots for (in terms of x): x*np.exp(-x)
    Input initial guess for root here: 2
    Input tolerance here: .00000001
    Input max number of iterations here: 25
    Do you want a table?
      (1) yes
      (2) no
    Enter here: 2
  
We need to input the functions as such using the numpy module and construction of python. The following input will yield 
the following output:

    g1 approximates the root of f as x =  9.860761315262648e-32
    g2 approximates the root of f as x =  4.639207134292721
  
**Implementation/Code:** The following is code for fnIter.py

    import numpy as np

    # All the below functions have been created to ask the user for certain values needed
    def fn():
        f = input("Enter function you want to find the roots for (in terms of x): ")
        return f

    def initialGuess():
        x0 = eval(input("Input initial guess for root here: "))
        return x0

    def tolerance():
        tol = eval(input("Input tolerance here: "))
        return tol

    def maxIter():
        mI = eval(input("Input max number of iterations here: "))
        return mI

    # Below are the two functions that we are using to find fixed points for
    def g1(f, x):
        gval = x - eval(f)
        return gval

    def g2(f, x):
        gval = x + eval(f)
        return gval

    def wantTable():
        print("Do you want a table?")
        print("\t1) Yes")
        print("\t2) No")
        choice = eval(input("Enter here: "))
        return choice

    def table(a,b,c):
        print("(1)" , a, " (2) ", b, " (3) ", c)

    # Here is the actual function for calculating the roots
    def functionalIteration():

        # Here we are calling the above funcitions to ask the user for values
        f = fn()
        x0 = initialGuess()

        # Saving our initial guess as a second variable to calculate the fixed point using
        # G1 and G2
        y0 = x0

        tol = tolerance()
        mI = maxIter()
        choice = wantTable()

        # Here we set variables that will be used in our while loops so it won't run infinitely
        error = 10 * tol
        iter = 0

        # Case where a user wants a table
        if choice == 1:
            print("Table for g1:")

            # Here is the afformentioned while loop that will run for as many iterations as the user
            # wants or until our error is smaller than the given tolerance
            while error > tol and iter < mI:

                # Calculate our initial guess for the root
                x1 = g1(f, x0)

                # Calculate a new error based on guess above
                error = np.abs(x1 - x0)

                # Set guess as our new "initial guess" so the loop will return a new guess and not x1 again
                x0 = x1

                # Create a line of our table
                table(iter + 1, x0, error)

                # Increase number of iterations as to make sure we don't run forever
                iter = iter + 1

            # Reset variables for loop so we can rerun the loop using g2
            # All the reasoning above is the same for the below code
            iter = 0
            error = 10 * tol
            print("Table for g2:")
            while error > tol and iter < mI:
                y1 = g2(f, y0)
                error = np.abs(y1 - y0)
                y0 = y1
                table(iter + 1, y0, error)
                iter = iter + 1

        # Case where user doesn't want a table, all the same reasoning for things as above
        elif choice == 2:
            while error > tol and iter < mI:
                x1 = g1(f, x0)
                error = np.abs(x1 - x0)
                x0 = x1
                iter = iter + 1
            error = 10 * tol
            iter = 0
            while error > tol and iter < mI:
                y1 = g2(f, y0)
                error = np.abs(y1 - y0)
                y0 = y1
                iter = iter + 1

            # Lastly return the two approximations of the root for the function
            print("g1 approximates the root of f as x = ", x0)
            print("g2 approximates the root of f as x = ", y0)
