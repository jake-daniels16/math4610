from Methods.vecAdd import vecAdd
from Methods.vecScalar import vecScalar
from Methods.vecSub import vecSub
from Methods.crossProduct import crossProduct
from Methods.dotProduct import dotProduct
from Methods.L1Norm import L1Norm
from Methods.L2Norm import L2Norm
from Methods.maxNorm import maxNorm
from Methods.tripleProduct import tripleProduct
from Methods.matAdd import matAdd
from Methods.matSub import matSub
from Methods.matProd import matProd
from Methods.matVecProd import matVecProd

def main():
    a = [1, 2, 3]
    b = [4, 5, 6]
    c = [7, 8, 9]
    v1 = vecAdd(a, b)
    v2 = vecSub(a, b)
    v3 = vecScalar(a, 2)
    v4 = L1Norm(a)
    v5 = L2Norm(a)
    v6 = maxNorm(a)
    v7 = dotProduct(a, b)
    v8 = crossProduct(a, b)
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

def matMain():
    A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    B = [[3, 2, 1], [6, 5, 4], [9, 8, 7]]
    a = [1, 2, 3]
    A1 = matAdd(A, B)
    A2 = matSub(A, B)
    A3 = matVecProd(A, a)
    A4 = matProd(A, B)
    print("A1 = ", A1)
    print("A2 = ", A2)
    print("A3 = ", A3)
    print("A4 = ", A4)

matMain()




