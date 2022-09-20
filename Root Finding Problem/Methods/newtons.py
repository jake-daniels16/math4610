# Jake Daniels
# MATH 4610

import numpy as np

def fn():
    f = input("Enter function you want to find the roots for (in terms of x): ")
    return f

def fPrime():
    fp = input("Enter derivative here: ")
    return fp

def f(fn, x):
    fval = eval(fn)
    return fval

def initialGuess():
    x0 = eval(input("Input initial guess for root here: "))
    return x0

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

def newtonsMethod():
    fun = fn()
    fp = fPrime()
    x0 = initialGuess()
    tol = tolerance()
    mI = maxIter()
    choice = wantTable()
    error = 10 * tol
    iter = 0
    if choice == 1:
        while error > tol and iter < mI:
            f0 = f(fun, x0)
            fp0 = f(fp, x0)
            x1 = x0 - f0 / fp0
            error = np.abs(x1 - x0)
            table(iter + 1, x1, error)
            iter = iter + 1
            x0 = x1
    elif choice == 2:
        while error > tol and iter < mI:
            f0 = f(fun, x0)
            fp0 = f(fp, x0)
            x1 = x0 - f0 / fp0
            error = np.abs(x1 - x0)
            iter = iter + 1
            x0 = x1
        print("Root approximation: ", x0)
