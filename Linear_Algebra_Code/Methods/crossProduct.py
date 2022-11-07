# Jake Daniels
# CS1400 - 001
# Assignment ??

import numpy as np

def crossProduct(a, b):
    if len(a) != 3 or len(b) != 3:
        print("Vectors must have 3 components")
        return None
    c = []
    c1 = a[1] * b[2] - a[2] * b[1]
    c2 = a[2] * b[0] - a[0] * b[2]
    c3 = a[0] * b[1] - a[1] * b[0]
    c.append(c1)
    c.append(c2)
    c.append(c3)
    return c
