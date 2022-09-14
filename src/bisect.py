# Jake Daniels
# MATH 4610

import numpy as np

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

def bisectMethod():
    fun = fn()
    a, b = eval(input("Enter interval for function as (a,b) where b>a: "))
    fa = f(fun, a)
    fb = f(fun, b)
    tol = tolerance()
    choice = wantTable()
    k = -np.log(tol / (b - a)) / np.log(2) + 1
    if choice == 1:
        # Not sure what values are wanted in the table
        for i in range(1, k):
            c = .5 * (a + b)
            fc = f(fun, c)
            if fa * fb > 0:
                print("Pick different a and b")
                print("f(a) x f(b) is positive")
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
                    break
                elif fb == 0:
                    print(b, "is a root")
                    break
                elif fc == 0:
                    print(c, "is a root")
                    break
    elif choice == 2:
        for i in range(1, k):
            c = .5 * (a + b)
            fc = f(fun, c)
            if fa * fb > 0:
                print("Pick different a and b")
                print("f(a) x f(b) is positive")
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
                    break
                elif fb == 0:
                    print(b, "is a root")
                    break
                elif fc == 0:
                    print(c, "is a root")
                    break