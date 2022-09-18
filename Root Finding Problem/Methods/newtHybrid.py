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

def newtonHybrid():
    fun = fn()
    fp = fPrime()
    a, b = eval(input("Enter interval for function as (a,b) where b > a: "))
    tol = tolerance()
    mI = maxIter()
    # choice = wantTable()
    x0 = .5 * (a + b)
    error = 10 * tol
    iter = 0
    while error > tol and iter < mI:
        f0 = f(fun, x0)
        fp0 = f(fp, x0)
        x1 = x0 - f0 / fp0
        newtError = np.abs(x1 - x0)
        if newtError > error:
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
            error = np.abs(b - a)
            x0 = .5 * (a + b)
        else:
            x0 = x1
            error = newtError
            iter = iter + 1
    print("Root approximation: ", x0)

