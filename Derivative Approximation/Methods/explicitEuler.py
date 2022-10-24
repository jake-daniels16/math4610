# Jake Daniels
# MATH 4610

import numpy as np
import matplotlib.pyplot as plt

def explicitEuler(f, x0, t0, T, n):
    h = (T - t0) / n
    f0 = f(t0, x0)
    tval = []
    xval = []
    tval.append(t0)
    xval.append(x0)
    for i in range(1, n):
        t1 = t0 + h
        x1 = x0 + h * f0
        x0 = x1
        t0 = t1
        tval.append(t0)
        xval.append(x0)
        f0 = f(t0, x0)
    return tval, xval
