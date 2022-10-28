# Jake Daniels
# MATH 4610

import numpy as np
from Methods.simpsons import simpsons
import matplotlib.pyplot as plt

def compConv(n):
    logError = []
    logH = []
    f = lambda x: np.exp(- x * x)
    exact = simpsons(f, 0, np.pi / 4, 1000)
    for i in range(0,8):
        sum = simpsons(f, 0, np.pi / 4, n)
        error = np.abs(exact - sum)
        logError.append(np.log(error))
        logH.append(np.log(1 / n))
        n = n * 2
    return logH, logError

logH, logError = compConv(4)
plt.plot(logH, logError)
plt.xlabel("log(h)")
plt.ylabel("log(error)")
plt.title("Convergence of Simpson's Rule")
plt.show()
