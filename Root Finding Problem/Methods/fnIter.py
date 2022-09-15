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

def functionalIteration():
    f = fn()
    x0 = initialGuess()
    y0 = x0
    tol = tolerance()
    mI = maxIter()
    choice = wantTable()
    error = 10 * tol
    iter = 0
    if choice == 1:
        print("Table for g1:")
        while error > tol and iter < mI:
            x1 = g1(f, x0)
            error = np.abs(x1 - x0)
            x0 = x1
            table(iter + 1, x0, error)
            iter = iter + 1
        iter = 0
        error = 10 * tol
        print("Table for g2:")
        while error > tol and iter < mI:
            y1 = g2(f, y0)
            error = np.abs(y1 - y0)
            y0 = y1
            table(iter + 1, y0, error)
            iter = iter + 1
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
        print("g1 approximates the root of f as x = ", x0)
        print("g2 approximates the root of f as x = ", y0)

