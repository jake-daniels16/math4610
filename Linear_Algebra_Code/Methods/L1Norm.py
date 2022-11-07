# Jake Daniels
# Math 4610

import numpy as np

def L1Norm(a):
    sum = 0
    for i in range(len(a)):
        sum += abs(a[i])
    return sum
