# Jake Daniels
# CS1400 - 001
# Assignment ??

import numpy as np

def dotProduct(a, b):
    if len(a) != len(b):
        print("Vectors must be the same length")
        return None
    sum = 0
    for i in range(len(a)):
        sum += a[i] * b[i]
    return sum
