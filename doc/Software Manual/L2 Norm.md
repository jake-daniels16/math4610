**Module Name:** L2Norm.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take a vector and return the L2 Norm

**Input:** a vector

**Output:** L2 Norm

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    v5 = L2Norm(a)
    print("v5 = ", v5)

Which ouputs the following value:

    v5 = 3.7416573867739413

**Implementation/Code:** The following is code for L2Norm.py

    # Import numpy so we can use square root function
    import numpy as np

    def L2Norm(a):
    
        # Initialize sum
        sum = 0
        
        # Loop over all components of vector
        for i in range(len(a)):
        
            # Add the square of each component
            sum += a[i]**2
            
        # Return L2 Norm which is the square root of the sum
        return np.sqrt(sum)
