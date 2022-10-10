# Jake Daniels
# MATH 4610

import numpy as np

def secondDerivative(f, x0, h):
    f0 = f(x0)
    f1 = f(x0 + h)
    f2 = f(x0 - h)
    print("f0: ", f0)
    print("f1: ", f1)
    print("f2: ", f2)
    fval = (f1 - 2 * f0 + f2) / (h * h)
    return fval

approx = secondDerivative(lambda x: (x - np.pi / 2) * np.tan(x) * np.tan(x) / (x * x + 65), np.pi / 4, 1.0)
print("Approximation: ", approx)
