# Jake Daniels
# Math 4610

import numpy as np

def vecScalar(a, b):
    c = np.zeros(len(a))
    for i in range(len(a)):
        c[i] = a[i] * b
    return c
