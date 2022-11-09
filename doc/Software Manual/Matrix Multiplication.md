**Module Name:** matProd.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two matrices and multiply them together

**Input:** A and B which are matrices where A has the same amount of columns as B has rows

**Output:** C, a matrix that is the product of the two matrices

**Usage/Example:** I wrote the following code to test it:

    A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    B = [[3, 2, 1], [6, 5, 4], [9, 8, 7]]
    A4 = matProd(A, B)
    print("A4 = ", A4)

Which ouputs the following matrix:

    A4 = [[42, 36, 30], [96, 81, 66], [150, 126, 102]]

**Implementation/Code:** The following is code for matProd.py

    def matProd(A, B):
    
        # Check that number of rows of A is equivalent to number of columns of B
        if len(A[0]) != len(B):
            print("Error: Incompatible dimensions")
            return
            
        # Initialize amount of rows and columns of A, as well as columns of B
        M = len(A)
        N = len(A[0])
        K = len(B[0])
        
        # Create a matrix that is has as many rows as A and columns as B
        C = [[0 for i in range(K)] for j in range(M)]
        
        # Loop over rows of A
        for m in range(M):
        
            # Loop over columns of B
            for k in range(K):
            
                # Loop over columns of A and rows of B
                for n in range(N):
                
                    # This is the step where we are computing the multiplication
                    # And we are adding the number to the corresponding [i][j] of C
                    C[m][k] += A[m][n] * B[n][k]
                    
        # Return new matrix
        return C
