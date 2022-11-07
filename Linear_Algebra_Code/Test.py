from Methods.vecAdd import vecAdd
from Methods.vecScalar import vecScalar
from Methods.vecSub import vecSub
from Methods.crossProduct import crossProduct
from Methods.dotProduct import dotProduct
from Methods.L1Norm import L1Norm
from Methods.L2Norm import L2Norm
from Methods.maxNorm import maxNorm
from Methods.tripleProduct import tripleProduct

def main():
    a = [1, 2, 3]
    b = [4, 5, 6]
    c = [7, 8, 9]
    v1 = vecAdd(a, b)
    v2 = vecSub(a, b)
    v3 = vecScalar(a, 2)
    v4 = crossProduct(a, b)
    v5 = dotProduct(a, b)
    v6 = L1Norm(a)
    v7 = L2Norm(a)
    v8 = maxNorm(a)
    v9 = tripleProduct(a, b, c)
    print("v1 = ", v1)
    print("v2 = ", v2)
    print("v3 = ", v3)
    print("v4 = ", v4)
    print("v5 = ", v5)
    print("v6 = ", v6)
    print("v7 = ", v7)
    print("v8 = ", v8)
    print("v9 = ", v9)

main()




