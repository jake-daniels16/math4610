# Jake Daniels
# MATH 4610

import numpy as np
from Methods.simpsons import simpsons
import matplotlib.pyplot as plt

def dataFitting(x, y, n):
    a11 = n+1
    a12 = x[0]
    for i in range(1, n):
        a12 = a12 + x[i]
    a21 = a12
    a22 = x[0] * x[0]
    for i in range(1, n):
        a22 = a22 + x[i] * x[i]
    b1 = y[0]
    for i in range(1, n):
        b1 = b1 + y[i]
    b2 = x[0] * y[0]
    for i in range(1, n):
        b2 = b2 + x[i] * y[i]
    detA = a11 * a22 - a12 * a21
    b = (b1 * a22 - b2 * a12) / detA
    a = (b2 * a11 - b1 * a21) / detA
    return a, b

def compConv(n):
    logError = []
    logH = []
    f = lambda x: np.exp(- x * x)
    error = 0
    for i in range(0,8):
        sum, hval, fval = simpsons(f, 0, np.pi / 4, n)
        for j in range(0, n+1):
            print("hval = ", hval[j], " fval = ", fval[j], "exact = ", f(hval[j]))
            approx = abs(fval[j] - f(hval[j]))
            error = error + approx ** 2
        error = np.sqrt(error) * np.sqrt(1 / n)
        logError.append(np.log(error))
        logH.append(np.log(1 / n))
        n = n * 2
    return logH, logError

logH, logError = compConv(4)
#plt.plot(logH, logError)
#plt.show()
