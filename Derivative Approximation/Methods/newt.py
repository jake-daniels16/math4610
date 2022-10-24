# Jake Daniels
# MATH 4610

import numpy as np

def table(a,b,c):
    print("(1)" , a, " (2) ", b, " (3) ", c)

def newtonsMethod(f, df, x0, tol, maxIter, choice):
    error = 10 * tol
    iter = 0
    if choice == "y":
        while error > tol and iter < maxIter:
            f0 = f(x0)
            df0 = df(x0)
            x1 = x0 - f0 / df0
            error = np.abs(x1 - x0)
            table(iter + 1, x1, error)
            iter = iter + 1
            x0 = x1
    elif choice == "n":
        while error > tol and iter < maxIter:
            f0 = f(x0)
            df0 = df(x0)
            x1 = x0 - f0 / df0
            error = np.abs(x1 - x0)
            iter = iter + 1
            x0 = x1
    return x0

