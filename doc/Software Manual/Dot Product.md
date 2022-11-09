**Module Name:** dotProduct.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two vectors and return the dot product

**Input:** two vectors of the same dimension

**Output:** dot product which is a scalar

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    b = [4, 5, 6]
    v6 = dotProduct(a, b)
    print("v6 = ", v6)

Which ouputs the following value:

    v6 = 32

**Implementation/Code:** The following is code for dotProduct.py

    def dotProduct(a, b):
    
        # Check to make sure vectors are of same dimension
        if len(a) != len(b):
            print("Vectors must be the same length")
            return None
            
        # Initialize sum
        sum = 0
        
        # Loop over entire vector
        for i in range(len(a)):
        
            # Add the product of each corresponding vector component
            sum += a[i] * b[i]
        
        # Return dot product
        return sum 
