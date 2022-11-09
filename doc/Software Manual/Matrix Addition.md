**Module Name:** matAdd.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two matrices and add them together

**Input:** a and b which are matrices of the same dimension

**Output:** c, a matrix that is the sum of the two matrices

**Usage/Example:** I wrote the following code to test it:

    A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    B = [[3, 2, 1], [6, 5, 4], [9, 8, 7]]
    A1 = matAdd(a, b)
    print("A1 = ", A1)

Which ouputs the following matrix:

    A1 = [[4, 4, 4], [10, 10, 10], [16, 16, 16]]

**Implementation/Code:** The following is code for matAdd.py

    def matAdd(A, B):
    
        # Initialize empty vector that will become matrix
        C = []
        
        # loop over all the rows of A
        for i in range(len(A)):
        
            # add a row to C for each row in A
            C.append([])
            
            # loop over the amount of components per row which is the number of columns
            for j in range(len(A[i])):
            
                Append the component of A and B summed together
                C[i].append(A[i][j] + B[i][j])
                
        # Return new matrix
        return C
