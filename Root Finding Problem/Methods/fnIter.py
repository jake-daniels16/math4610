# Jake Daniels
# MATH 4610

import numpy as np

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

def g(f, x):
    if x > 1:
        gval = x + eval(f)
        return gval
    else:
        gval = x - eval(f)
        return gval

def wantTable():
    print("Do you want a table?")
    print("\t1) Yes")
    print("\t2) No")
    choice = eval(input("Enter here: "))
    return choice

def table(a,b,c):
    print("(1)" , a, " (2) ", b, " (3) ", c)

# Using g(x) = x - f(x) makes the derivative of g greater than one for all x > 1 for f(x) = x * e^-x
# Using g(x) = x + f(x) makes the derivative of g greater than one for all x < 1 for above f(x)
# Going to account for this by making an if else statement

def functionalIteration():
    f = fn()
    x0 = initialGuess()
    tol = tolerance()
    mI = maxIter()
    choice = wantTable()
    error = 10 * tol
    iter = 0
    if choice == 1:
        while error > tol and iter < mI:
            x1 = g(f, x0)
            error = np.abs(x1 - x0)
            x0 = x1
            table(iter, x0, error)
            iter = iter + 1
    elif choice == 2:
        while error > tol and iter < mI:
            x1 = g(f, x0)
            error = np.abs(x1 - x0)
            x0 = x1
            iter = iter + 1
        print("The root of f is at x = ", x0)

