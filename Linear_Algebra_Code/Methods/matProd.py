# Jake Daniels
# Math 4610

def matProd(A, B):
    if len(A[0]) != len(B):
        print("Error: Incompatible dimensions")
        return
    M = len(A)
    N = len(A[0])
    K = len(B[0])
    C = [[0 for i in range(K)] for j in range(M)]
    for m in range(M):
        for k in range(K):
            for n in range(N):
                C[m][k] += A[m][n] * B[n][k]
    return C
