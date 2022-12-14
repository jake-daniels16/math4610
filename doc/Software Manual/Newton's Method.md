**Module Name:** newtons.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will compute an approximation of a root for any given function using Newton’s Method.

**Input:** The user will need to input a function, f, and the derivative of that function, f’. They will also need to give an
initial guess for the root of f, as well as a max number of iterations and a tolerance.

**Output:** The function will return a single approximation of a root for the given function.

**Usage/Example:** We will answer the following prompts as follows for the example of f (x) = xe−x:

    Enter function you want to find the roots for (in terms of x): x*np.exp(-x)
    Enter derivative here: np.exp(-x) - x*np.exp(-x)
    Input initial guess for root here: .5
    Input tolerance here: .00000001
    Input max number of iterations here: 25

We need to input the functions as such using the numpy module and construction of python. The following input will yield 
the following output:

    Root approximation:  -8.80999858950826e-27
  
Which is approximately zero, so using this approximation we can guess that the function above has a root at or near x=0.

**Implementation/Code:** The following is code for newton.py

    # This is the module that allows us to input functions involving elementary functions like (e, sin, cos,...)
    import numpy as np

    # This is the function that will be used to ask the user for the function
    def fn():
        f = input("Enter function you want to find the roots for (in terms of x): ")
        return f

    # This is the function that will ask the user for the derivative
    def fPrime():
        fp = input("Enter derivative here: ")
        return fp

    # This is the function that will compute a function, at a value, x
    def f(fn, x):
        fval = eval(fn)
        return fval

    # This is the function that will ask the user for an initial guess
    def initialGuess():
        x0 = eval(input("Input initial guess for root here: "))
        return x0

    # This function asks the user for the tolerance wanted
    def tolerance():
        tol = eval(input("Input tolerance here: "))
        return tol

    # This function asks the user for the max number of iterations
    def maxIter():
        mI = eval(input("Input max number of iterations here: "))
        return mI

    # Here is the function that will ask the user if they want a table, and return their decision
    def wantTable():
        print("Do you want a table?")
        print("\t1) Yes")
        print("\t2) No")
        choice = eval(input("Enter here: "))
        return choice

    # Here is the function that will actually create the table, that will print lines with the wanted values
    def table(a,b,c):
        print("(1)" , a, " (2) ", b, " (3) ", c)

    # Below is the function that actually compiles all these functions to compute the approximation
    def newtonsMethod():
        # Below we are asking the user for everything they want
        fun = fn()
        fp = fPrime()
        x0 = initialGuess()
        tol = tolerance()
        mI = maxIter()

        # This is where the user is asked if they want a table
        choice = wantTable()

        # We set an iteration counter and an initial error so that we can make the following while loop
        error = 10 * tol
        iter = 0

        # 1 corresponds to when the user selects, yes, they want a table
        if choice == 1:

          # This while loop will run until the error is less than the tolerance or we hit the maximum number of iterations
          while error > tol and iter < mI:

              # Here we compute the values of the function and derivative and save them as variables
              f0 = f(fun, x0)
              fp0 = f(fp, x0)

              # We compute the approximation of the root
              x1 = x0 - f0 / fp0

              # Update error and iteration number to make sure the loop is updated to see if it needs to stop
              error = np.abs(x1 - x0)
              iter = iter + 1

              # By passing the iterations, approximation, and error into this table function we create the wanted table
              table(iter, x1, error)

              # Reset initial variable as initial approximation to continue the loop and obtain the next approximation
              x0 = x1

        # 2 corresponds to when the user does not want a table so we remove the table function and add the last print statement
        elif choice == 2:

            while error > tol and iter < mI:
                f0 = f(fun, x0)
                fp0 = f(fp, x0)
                x1 = x0 - f0 / fp0
                error = np.abs(x1 - x0)
                iter = iter + 1
                x0 = x1

           # Take the last approximation given once loop ends and print it for the user to see
           print("Root approximation: ", x0)
