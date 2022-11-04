**Module Name:** bisect.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will compute an approximation of a root for any given continuous function. We will give
the code two x values, a and b, such that f(a)f(b)<0 and it will take the midpoint of a and b, lets call it c and repeat
the same process until it finds a root.

**Input:** The user will need to input a function, f, an interval [a,b], as well as a max number of iterations and a tolerance.

**Output:** The function will return a single approximation of a root for the given function.

**Usage/Example:** We will answer the following prompts as follows for the example of f (x) = x*np.exp(-x):

    Enter function you want to find the roots for (in terms of x): x*np.exp(-x)
    Enter interval for function as (a,b) where b>a: -10, 14
    Input tolerance here: .00000001
    Input max number of iterations here: 25
    Do you want a table?
      (1) yes
      (2) no
    Enter here: 1

We need to input the functions as such using the numpy module and construction of python. The following input will yield 
the following table excluding the middle to save space:

    (1) 1  (2)  2.0  (3)  24
    ...
    (1) 31  (2)  -3.725290298461914e-09  (3)  2.2351741790771484e-08

**Implementation/Code:** The following is code for bisect.py

    import numpy as np

    # Below are functions set up to ask the user for specific values needed
    def fn():
        f = input("Enter function you want to find the roots for (in terms of x): ")
        return f

    def f(fn, x):
        fval = eval(fn)
        return fval

    def tolerance():
        tol = eval(input("Input tolerance here: "))
        return tol

    def maxIter():
        mI = eval(input("Input max number of iterations here: "))
        return mI

    def wantTable():
        print("Do you want a table?")
        print("\t1) Yes")
        print("\t2) No")
        choice = eval(input("Enter here: "))
        return choice

    def table(a,b,c):
        print("(1)" , a, " (2) ", b, " (3) ", c)

    # Here is the actual funciton that will compute the root
    def bisectMethod():

        # Here I am calling above functions to get the necessary values
        fun = fn()
        a, b = eval(input("Enter interval for function as (a,b) where b > a: "))
        fa = f(fun, a)
        fb = f(fun, b)
        tol = tolerance()
        choice = wantTable()

        # Instead of using a while loop, using some properties of the bisect method
        # we can instead use this k value to set up a valid for loop
        k = int(-np.log(tol / np.abs(b - a)) / np.log(2)) + 1

        # Case where user wants table
        if choice == 1:

            # Take the loop up until the k value calculated using the values given by
            # the user
            for i in range(1, k):

                # Calculating an error based on interval given
                error = np.abs(b-a)

                # Calculating midpoint c and evaluating function at c
                c = .5 * (a + b)
                fc = f(fun, c)

                # If user give invalid interval, breaks loop
                if fa * fb > 0:
                    print("Pick different a and b")
                    print("f(a) x f(b) is positive")
                    break

                # If f(a)f(c)<0 then ignore the interval given by [c,b] and focus on [a,c]
                elif fa * fc < 0:
                    b = c
                    fb = fc

                # If f(b)f(c)<0 then ignore the interval given by [a,c] and focus on [c,b]
                elif fb * fc < 0:
                    a = c
                    fa = fc

                # Below I accounted for when a root is found or one of [a,b] is a root
                elif fb * fa * fc == 0:
                    if fa == fb == 0:
                        print("Both endpoints are roots no table could be formed.")
                        break
                    elif fa == 0:
                        print("The left endpoint, ", a, ", is a root no table could be formed.")
                        break
                    elif fb == 0:
                        print("The right endpoint, ", b, ", is a root no table could be formed.")
                        break
                    elif fc == 0:
                        table(i, c, error)
                        break

                # Here I print out a line of the table
                table(i, c, error)

        # Case where user does not want a table, all justification for code is the same as above
        elif choice == 2:
            for i in range(1, k):
                c = .5 * (a + b)
                fc = f(fun, c)
                if fa * fb > 0:
                    print("Pick different a and b")
                    print("f(a) x f(b) is positive")
                    c = " "
                    break
                elif fa * fc < 0:
                    b = c
                    fb = fc
                elif fb * fc < 0:
                    a = c
                    fa = fc
                elif fb * fa * fc == 0:
                    if fa == fb == 0:
                        print(a, "and", b, "are roots")
                        break
                    elif fa == 0:
                        print(a, "is a root")
                        c = "given above"
                        break
                    elif fb == 0:
                        print(b, "is a root")
                        c = "given above"
                        break
                    elif fc == 0:
                        print(c, "is a root")
                        c = "given above"
                        break
            # Print final approximation out
            print("Root approximation: ", c)
