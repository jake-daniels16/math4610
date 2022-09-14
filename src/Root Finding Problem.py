# Jake Daniels
# MATH 4610

from Methods.fnIter import functionalIteration
from Methods.bisect import bisectMethod

print("Methods")
print("\t1) Fixed Point Iteration")
print("\t2) Bisect Method")

choice = eval(input("What method do you want to do? "))
if choice == 1:
    functionalIteration()
elif choice == 2:
    bisectMethod()
