# Jake Daniels
# MATH 4610

import numpy as np

def simpsons(f, a, b, n):
    h = (b - a) / n
    sum  = f(a) + f(b)
    hval = []
    fval = []
    hval.append(a)
    fval.append(f(a))
    for i in range(1, n):
        x = a + i * h
        fx = f(x)
        hval.append(x)
        fval.append(fx)
        if i % 2 == 0:
            sum = sum + 2 * fx
        else:
            sum = sum + 4 * fx
    hval.append(b)
    fval.append(f(b))
    sum = sum * h / 3
    return sum, hval, fval

for i in range(1, 5):
    n = 2 ** i
    sum, h, f = simpsons(lambda x: np.exp(- x * x), 0, np.pi / 4, n)
    print("n = ", n, " ", sum)
