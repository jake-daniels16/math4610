# Jake Daniels
# MATH 4610

import numpy as np

def trapezoid(f, a, b, n):
    h = (b - a) / n
    hval = []
    fval = []
    hval.append(a)
    fval.append(f(a))
    sum = 0.5 * (f(a) + f(b))
    for i in range(1, n):
        x = a + i * h
        fx = f(x)
        hval.append(x)
        hval.append(fx)
        sum = sum + fx
    hval.append(b)
    fval.append(f(b))
    sum = sum * h
    return sum, hval, fval

for i in range(1, 5):
    n = 2 ** i
    sum, h, f = trapezoid(lambda x: np.exp(- x * x), 0, np.pi / 4, n)
    print("n = ", n, " ", sum)




