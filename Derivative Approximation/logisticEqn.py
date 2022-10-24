# Jake Daniels
# MATH 4610

import numpy as np
import matplotlib as plt
from Methods.explicitEuler import explicitEuler
from Methods.implicitEuler import implicitEuler

def logisticEquation(a, b, p0):
    p = lambda t, x: a * x - b * x * x
    dp = lambda t, x: a - 2 * b * x
    tval1, pval1 = explicitEuler(p, p0, 0, 10, 100)
    tval2, pval2 = implicitEuler(p, dp, p0, 0, 10, 100)
    return tval1, pval1, tval2, pval2

tApprox1, xApprox1, tApprox2, xApprox2 = logisticEquation(0.2, 0.0005, 10.0)
tApprox3, xApprox3, tApprox4, xApprox4 = logisticEquation(0.01, 0.0005, 10.0)
tApprox5, xApprox5, tApprox6, xApprox6 = logisticEquation(2.0, 0.0005, 10.0)
plt.plot(tApprox2, xApprox2, color='red')
plt.xlabel('t')
plt.ylabel('P(t)')
plt.show()
plt.plot(tApprox4, xApprox4, color='blue')
plt.xlabel('t')
plt.ylabel('P(t)')
plt.show()
plt.plot(tApprox6, xApprox6, color='green')
plt.xlabel('t')
plt.ylabel('P(t)')
plt.show()
