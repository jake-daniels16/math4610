# Jake Daniels
# MATH 4610

import numpy as np
from Methods.newt import newtonsMethod

def implicitEuler(f, df, x0, t0, T, n):
    h = (T - t0) / n
    f0 = f(t0, x0)
    tval = []
    xval = []
    tval.append(t0)
    xval.append(x0)
    for i in range(1, n):
        t1 = t0 + h
        x1 = newtonsMethod(lambda x: x - x0 - h * f(t1, x), lambda x: 1 - h * df(t1, x), x0, .00000001, 50, "n")
        x0 = x1
        t0 = t1
        tval.append(t0)
        xval.append(x0)
    return tval, xval

