# Jake Daniels
# Math 4610

def matVecProd(A, b):
    if len(A[0]) != len(b):
        print("Error: Incompatible dimensions")
        return
    M = len(A)
    N = len(A[0])
    sum = 0
    c = []
    for i in range(M):
        for j in range(N):
            sum += A[i][j] * b[j]
        c.append(sum)
        sum = 0
    return c
