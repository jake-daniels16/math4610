# Jake Daniels
# MATH 4610

import numpy as np

def fn():
    f = input("Enter function you want to find the roots for (in terms of x): ")
    return f

def f(fn, x):
    fval = eval(fn)
    return fval

def initialGuesses():
    x0, x1 = eval(input("Input initial guesses for root here as (x0, x1): "))
    return x0, x1

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

def secantMethod():
    fun = fn()
    x0, x1 = initialGuesses()
    tol = tolerance()
    mI = maxIter()
    choice = wantTable()
    error = 10 * tol
    iter = 0
    f0 = f(fun, x0)
    f1 = f(fun, x1)
    if choice == 1:
        while error > tol and iter < mI:
            x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0)
            error = np.abs(x2 - x1)
            table(iter + 1, x2, error)
            iter = iter + 1
            x0 = x1
            x1 = x2
            f0 = f1
            f1 = f(fun, x2)
    elif choice == 2:
        while error > tol and iter < mI:
            x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0)
            error = np.abs(x2 - x1)
            iter = iter + 1
            x0 = x1
            x1 = x2
            f0 = f1
            f1 = f(fun, x2)
        print("Root approximation: ", x1)
