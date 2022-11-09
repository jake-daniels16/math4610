# Jake Daniels
# Math 4610

from Methods.explicitEuler import explicitEuler

def eApprox(f, x0, t0, T, n):
    t, x = explicitEuler(f, x0, t0, T, n)
    return x[n-1]

n=10
for i in range(6):
    approx = eApprox(lambda t, x: x, 1, 0, 1, n)
    print("n :", n, "e Approximation: ", approx)
    n = n * 10
