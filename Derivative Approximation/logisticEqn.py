# Jake Daniels
# MATH 4610

import numpy as np
import matplotlib.pyplot as plt
from Methods.explicitEuler import explicitEuler
from Methods.implicitEuler import implicitEuler

def logisticEquation(a, b, p0):
    p = lambda t, x: a * x - b * x * x
    dp = lambda t, x: a - 2 * b * x
    tval1, pval1 = explicitEuler(p, p0, 0, 10, 100)
    tval2, pval2 = implicitEuler(p, dp, p0, 0, 10, 100)
    tval3, pval3 = exactLogistic(a, b, p0, 10, 100)
    return tval1, pval1, tval2, pval2, tval3, pval3

def exactLogistic(a, b, p0, T, n):
    h = T / n
    tval = []
    pval = []
    t0 = 0
    tval.append(t0)
    pval.append(p0)
    for i in range(1, n):
        t1 = t0 + h
        p1 = (a * p0 * np.exp(a * t1)) / (a + b * p0 * (np.exp(a * t1) - 1))
        tval.append(t1)
        pval.append(p1)
        t0 = t1
    return tval, pval

tApprox1, xApprox1, tApprox2, xApprox2, tApprox3, xApprox3 = logisticEquation(0.2, 0.0005, 10.0)
tApprox4, xApprox4, tApprox5, xApprox5, tApprox6, xApprox6 = logisticEquation(0.01, 0.0005, 10.0)
tApprox7, xApprox7, tApprox8, xApprox8, tApprox9, xApprox9 = logisticEquation(2.0, 0.0005, 10.0)
plt.title("Example 1")
plt.plot(tApprox1, xApprox1, color='red')
plt.plot(tApprox2, xApprox2, color='blue')
plt.plot(tApprox3, xApprox3, color='green')
plt.xlabel('t')
plt.ylabel('P(t)')
plt.show()
plt.title("Example 2")
plt.plot(tApprox4, xApprox4, color='red')
plt.plot(tApprox5, xApprox5, color='blue')
plt.plot(tApprox6, xApprox6, color='green')
plt.xlabel('t')
plt.ylabel('P(t)')
plt.show()
plt.title("Example 3")
plt.plot(tApprox7, xApprox7, color='red')
plt.plot(tApprox8, xApprox8, color='blue')
plt.plot(tApprox9, xApprox9, color='green')
plt.xlabel('t')
plt.ylabel('P(t)')
plt.show()
