**Module Name:** maxNorm.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take a vector and return the Max Norm

**Input:** a vector

**Output:** Max Norm

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    v6 = maxNorm(a)
    print("v5 = ", v5)

Which ouputs the following value:

    v5 = 3

**Implementation/Code:** The following is code for maxNorm.py

    def maxNorm(a):
    
        # Initialize max value
        max = 0
        
        # Loop over entire vector
        for i in range(len(a)):
        
            # Compare absolute value of each component to max and if it is greater replace max with that value
            if abs(a[i]) > max:
                max = abs(a[i])
                
        # Return max Norm
        return max
