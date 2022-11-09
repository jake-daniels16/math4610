**Module Name:** L1Norm.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take a vector and return the L1 Norm

**Input:** a vector

**Output:** L1 Norm

**Usage/Example:** I wrote the following code to test it:

    a = [1, 2, 3]
    v4 = L1Norm(a)
    print("v4 = ", v4)

Which ouputs the following value:

    v4 = 6

**Implementation/Code:** The following is code for L1Norm.py

    def L1Norm(a):
        # Initialize sum
        sum = 0
        
        # Loop over full vector
        for i in range(len(a)):
        
            # Add absolute value of each component to sum
            sum += abs(a[i])
            
        # Return norm
        return sum 
