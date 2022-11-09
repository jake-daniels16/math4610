**Module Name:** matVecProd.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take the product of a matrix and a vector

**Input:** A, a matrix, and a, a vector

**Output:** c, resulting vector

**Usage/Example:** I wrote the following code to test it:

    A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    a = [1, 2, 3]
    A3 = matVecProd(A, a)
    print("A3 = ", A3)

Which ouputs the following matrix:

    A3 = [14, 32, 50]

**Implementation/Code:** The following is code for matVecProd.py:

    def matVecProd(A, b):
    
        # Check to make sure the amount of columns of A is equivalent to rows of b
        if len(A[0]) != len(b):
            print("Error: Incompatible dimensions")
            return
            
        # Initialize lengths, sum, and empty vector
        M = len(A)
        N = len(A[0])
        sum = 0
        c = []
        
        # Loop over rows of A
        for i in range(M):
        
            # Loop over columns of A/rows of b
            for j in range(N):
            
                # Add each component of a row of A by the same row of b
                sum += A[i][j] * b[j]
                
            # Append this to the empty vector
            c.append(sum)
            
            # Reset sum to zero so that the next loop will calculate the next component
            sum = 0
            
        # Return vector
        return c
