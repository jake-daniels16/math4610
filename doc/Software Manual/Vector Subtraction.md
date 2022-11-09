**Module Name:** vecSub.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two vectors and take the difference of them

**Input:** a and b which are vectors of the same dimension

**Output:** c the difference of the two vectors

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    b = [4, 5, 6]
    v2 = vecSub(a, b)
    print("v2 = ", v2)

Which ouputs the following vector:

    v2 = [-3, -3, -3]

**Implementation/Code:** The following is code for vecAdd.py

    def vecSub(a, b):
        
        # Want to make sure the vectors are of the same dimension or they won't be able to be subtracted
        if len(a) != len(b):
            print("Vectors must be the same length")
            
            # Returns nothing so that the user will reinput appropriate vectors
            return None
        
        # Start by creating an empty vector c
        c = []
        
        # Loop over length of the vectors
        for i in range(len(a)):
        
            # Append the difference of the components for all components of a and b to c
            c.append(a[i] + b[i])
        
        # Return new vector
        return c
