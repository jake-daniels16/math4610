# Jake Daniels
# MATH 4610

import numpy as np

def secondDerivative(f, x0, h):
    f0 = f(x0)
    for i in range (1, 20):
        f1 = f(x0 + h)
        f2 = f(x0 - h)
        fval = (f1 - 2 * f0 + f2) / (h * h)
        h = h / 2
    return fval

approx = secondDerivative(lambda x: (x - np.pi / 2) * np.tan(x) * np.tan(x) / (x * x + 65), np.pi / 4, 1.0)
print("Approximation: ", approx)
