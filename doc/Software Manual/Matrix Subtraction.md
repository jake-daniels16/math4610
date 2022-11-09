**Module Name:** matSub.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two matrices and subtract B from A

**Input:** A and B which are matrices of the same dimension

**Output:** C, a matrix that is the difference of the two matrices

**Usage/Example:** I wrote the following code to test it:

    A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    B = [[3, 2, 1], [6, 5, 4], [9, 8, 7]]
    A2 = matSub(A, B)
    print("A2 = ", A2)

Which ouputs the following matrix:

    A2 = [[-2, 0, 2], [-2, 0, 2], [-2, 0, 2]]

**Implementation/Code:** The following is code for matSub.py

    def matSub(A, B):
    
        # Initialize empty vector that will become matrix
        C = []
        
        # loop over all the rows of A
        for i in range(len(A)):
        
            # add a row to C for each row in A
            C.append([])
            
            # loop over the amount of components per row which is the number of columns
            for j in range(len(A[i])):
            
                Append the component of the difference of A and B
                C[i].append(A[i][j] - B[i][j])
                
        # Return new matrix
        return C
