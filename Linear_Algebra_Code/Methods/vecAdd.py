# Jake Daniels
# Math 4610

import numpy as np

def vecAdd(a, b):
    if len(a) != len(b):
        print("Vectors must be the same length")
        return None
    c = np.zeros(len(a))
    for i in range(len(a)):
        c[i] = a[i] + b[i]
    return c
