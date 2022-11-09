**Module Name:** crossProduct.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two vectors and return the cross product

**Input:** two vectors of dimension 3

**Output:** cross product which will be a vector

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    b = [4, 5, 6]
    v8 = crossProduct(a, b)
    print("v8 = ", v8)

Which ouputs the following vector:

    v8 = [-3, 6, -3]

**Implementation/Code:** The following is code for crossProduct.py

    def crossProduct(a, b):
        # Check to make sure both vectors are dimension 3 because this is the only dimension cross products exists
        if len(a) != 3 or len(b) != 3:
            print("Vectors must have 3 components")
            return None
            
        # Initialize empty vector
        c = []
        
        # From doing the calculation generally we get the following three equations for the components of c
        c1 = a[1] * b[2] - a[2] * b[1]
        c2 = a[2] * b[0] - a[0] * b[2]
        c3 = a[0] * b[1] - a[1] * b[0]
        
        # Append above components
        c.append(c1)
        c.append(c2)
        c.append(c3)
        
        # Return vector
        return c 
