**Module Name:** tripleProduct.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two vectors and return the triple product

**Input:** three vectors of dimension 3

**Output:** triple product

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    b = [4, 5, 6]
    c = [7, 8, 9]
    v9 = tripleProduct(a, b, c)
    print("v9 = ", v9)

Which ouputs the following value:

    v9 = 0

**Implementation/Code:** The following is code for tripleProduct.py

    # Import dot and cross product
    from Methods.dotProduct import dotProduct
    from Methods.crossProduct import crossProduct

    def tripleProduct(a, b, c):
        
        # Verify that all 3 are dimension three
        if len(a) != 3 or len(b) != 3 or len(c) != 3:
            return "Error: Input vectors must be 3D"
        
        # If they are all three then calculate the triple product and return it
        else:
            return dotProduct(a, crossProduct(b, c))
