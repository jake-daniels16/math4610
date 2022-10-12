# Jake Daniels
# MATH 4610

import numpy as np
from Methods.secondDerivative import secondDerivative
from Methods.dataFitting import dataFitting

def main():
    exact = -0.0548915699521
    hVals, fVals, diff = secondDerivative(lambda x: (x - np.pi / 2) * np.tan(x) * np.tan(x) / (x * x + 65), 1.0,
                                          1.0, exact)
    a, b = dataFitting(hVals, diff, 19)
    print("y = ", a, "x + ", b)

main()


