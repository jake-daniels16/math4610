# Jake Daniels
# MATH 4610

import numpy as np

def simpsons(f, a, b, n):
    h = (b - a) / n
    sum  = f(a) + f(b)
    for i in range(1, n):
        x = a + i * h
        if i % 2 == 0:
            sum = sum + 2 * f(x)
        else:
            sum = sum + 4 * f(x)
    sum = sum * h / 3
    return sum

for i in range(1, 5):
    n = 2 ** i
    print("n = ", n, " ", simpsons(lambda x: np.exp(- x * x), 0, np.pi / 4, n))
