**Module Name:** vecScalar.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take a vector and multiply each component by a number

**Input:** a vector and a scalar

**Output:** c the scaled vector

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    v3 = vecScalar(a, 2)
    print("v3 = ", v3)

Which ouputs the following vector:

    v3 = [2, 4, 6]

**Implementation/Code:** The following is code for vecAdd.py

    def vecScalar(a, b):
    
        # Create empty vector
        c = []
        
        # Loop over entire length of our vector a
        for i in range(len(a)):
        
            # Append each the a component multiplied by b
            c.append(a[i] * b)
            
        # Return new vector
        return c
