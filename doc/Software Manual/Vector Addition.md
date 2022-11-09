**Module Name:** vecAdd.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two vectors and add them together

**Input:** a and b which are vectors of the same dimension

**Output:** c the sum of the two vectors

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    b = [4, 5, 6]
    v1 = vecAdd(a, b)
    print("v1 = ", v1)

Which ouputs the following vector:

    v1 = [5, 7, 9]

**Implementation/Code:** The following is code for vecAdd.py

    def vecAdd(a, b):
        
        # Want to make sure the vectors are of the same dimension or they won't be able to be added together
        if len(a) != len(b):
            print("Vectors must be the same length")
            
            # Returns nothing so that the user will reinput appropriate vectors
            return None
        
        # Start by creating an empty vector c
        c = []
        
        # Loop over length of the vectors
        for i in range(len(a)):
        
            # Append the sum of the components for all components of a and b to c
            c.append(a[i] + b[i])
        
        # Return new vector
        return c
