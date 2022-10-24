# Jake Daniels
# MATH 4610

import numpy as np

def trapezoid(f, a, b, n):
    h = (b - a) / n
    sum = 0.5 * (f(a) + f(b))
    for i in range(1, n):
        x = a + i * h
        sum = sum + f(x)
    sum = sum * h
    return sum

for i in range(1, 5):
    n = 2 ** i
    print("n = ", n, " ", trapezoid(lambda x: np.exp(- x * x), 0, np.pi / 4, n))




