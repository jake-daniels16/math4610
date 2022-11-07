# Jake Daniels
# Math 4610

def matSub(A, B):
    C = []
    for i in range(len(A)):
        C.append([])
        for j in range(len(A[i])):
            C[i].append(A[i][j] - B[i][j])
    return C
