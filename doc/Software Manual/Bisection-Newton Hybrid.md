**Module Name:** newtHybrid.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will compute an approximation of a root for any given function using a hybrid of
Newton's method and the bisection method. The idea is that if Newton's method will not compute an appropriate 
approximation right away, we can use the bisection to get closer to a root and then switch back to Newton's Method
to find the root.

**Input:** The user will need to input a function, f, and the derivative of that function, f’. They will also need to give an
initial interval, as well as a max number of iterations and a tolerance.

**Output:** The function will return a single approximation of a root for the given function.

**Usage/Example:** We will answer the following prompts as follows for the example of f (x) = 10.14 e^{x^2} cos(pi/x):

    Enter function you want to find the roots for (in terms of x): 10.14 * np.exp(x * x) * np.cos(np.pi / x)
    Enter derivative here: 10.14 * (2 * x * np.exp(x * x) * np.cos(np.pi / x) + (np.pi /  (x * x)) * np.exp(x * x) * np.sin(np.pi / x))
    Enter interval for function as (a,b) where b > a: .5, 1.4
    Input tolerance here: .00000001
    Input max number of iterations here: 25

We need to input the functions as such using the numpy module and construction of python. The following input will yield 
the following output:

    Root approximation:  0.6666666666666667
  
Which is approximately 2/3, so using this approximation we can guess that the function above has a root at or near x=2/3.

**Implementation/Code:** The following is code for newtHybrid.py

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

    # This function asks the user for the tolerance wanted
    def tolerance():
        tol = eval(input("Input tolerance here: "))
        return tol

    # This function asks the user for the max number of iterations
    def maxIter():
        mI = eval(input("Input max number of iterations here: "))
        return mI

    # This is the function that compiles all the above function, and finds the root for the user
    def newtonHybrid():

        # Here we are asking the user for the function and the derivative
        fun = fn()
        fp = fPrime()

        # Here we find the initial interval the user wants to look at
        a, b = eval(input("Enter interval for function as (a,b) where b > a: "))

        # Here we get an idea of how close the user wants their approximation to be
        tol = tolerance()
        mI = maxIter()

        # We set the first guess that we will run through Newton's Method to be the center of the interval given
        x0 = .5 * (a + b)

        # We set up these two variables to control the while loop before so it doesn't run forever
        error = 10 * tol
        iter = 0

        # The while loop runs until the max number of iterations has been ran, or the error is greater than the user's
        given tolerance
        while error > tol and iter < mI:

            # We calculate the function and the derivative at the x0 given above
            f0 = f(fun, x0)
            fp0 = f(fp, x0)

            # Here we calculate the approximation
            x1 = x0 - f0 / fp0

            # We create a new variable for the error we get from our first run through using Newton's Method
            newtError = np.abs(x1 - x0)

            # If the size of our interval we are looking at after the first iteration of Newton's Method is greater
            than our starting interval, then we jump and do 4 iterations of bisection method to shrink that interval
            and get a little closer to the root so that Newton's Method will work
            if newtError > error:

                # This is just the code for the bisection method
                fa = f(fun, a)
                fb = f(fun, b)
                for i in range(1, 4):
                    c = .5 * (a + b)
                    fc = f(fun, c)
                    if fa * fc < 0:
                        b = c
                        fb = fc
                    elif fb * fc < 0:
                        a = c
                        fa = fc

                # We now redefine our error to be the size of the new interval
                error = np.abs(b - a)

                # We again pick x0 to be the midpoint of our interval and run it through Newton's Method again
                x0 = .5 * (a + b)

            # If newtError < error then Newton's method is working and we want to continue using that
            else:
                x0 = x1
                error = newtError
                iter = iter + 1
        print("Root approximation: ", x0)
