# Jake Daniels
# MATH 4610

from Methods.fnIter import functionalIteration
from Methods.bisect import bisectMethod
from Methods.newtons import newtonsMethod
from Methods.secant import secantMethod
from Methods.newtHybrid import newtonHybrid

print("Methods")
print("\t1) Fixed Point Iteration")
print("\t2) Bisect Method")
print("\t3) Newton's Method")
print("\t4) Secant Method")
print("\t5) Newton Bisect Hybrid")

choice = eval(input("What method do you want to do? "))
if choice == 1:
    functionalIteration()
elif choice == 2:
    bisectMethod()
elif choice == 3:
    newtonsMethod()
elif choice == 4:
    secantMethod()
elif choice == 5:
    newtonHybrid()
