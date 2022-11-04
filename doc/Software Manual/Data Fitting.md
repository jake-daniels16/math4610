**Module Name:** dataFitting.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will take two vectors for x and y values and interpolate them to a linear function

**Input:** X vector and Y vector as well as an n value corresponding to the length of the vectors

**Output:** The function will return values a and b, such that y = a * x + b is the linear function for the data.

**Usage/Example:** I wrote the following code to use this module:

    import numpy as np
    from Methods.secondDerivative import secondDerivative
    from Methods.dataFitting import dataFitting

    def main():
        exact = -0.0548915699521
        hVals, fVals, diff = secondDerivative(lambda x: (x - np.pi / 2) * np.tan(x) * np.tan(x) / (x * x + 65), 1.0,
                                              1.0, exact)
        a, b = dataFitting(hVals, diff, 19)
        print("y = ", a, "x + ", b)

    main()

Which returned:
  
    y =  -0.013871376778266133 x +  -0.11840202632508127

**Implementation/Code:** The following is code for dataFitting.py

  import numpy as np

  def dataFitting(x, y, n):

      # a11, a12, a21, and a22 correspond to entries to a 2x2 matrix A where A[b, a]^T=[b1,b2]^T
      # from our calculation in class we found that the top left entry must be n+1
      a11 = n+1

      # from our calculation the top right must besum of all x values
      a12 = x[0]
      for i in range(1, n):
          a12 = a12 + x[i]

      # the bottom left must be the sum of all x values as well
      a21 = a12

      # the bottom right must be the sum of all x*x values
      a22 = x[0] * x[0]
      for i in range(1, n):
          a22 = a22 + x[i] * x[i]

      # below we calculate b1 and b2 which are the sum of y values and the sum of x*y values 
      b1 = y[0]
      for i in range(1, n):
          b1 = b1 + y[i]
      b2 = x[0] * y[0]
      for i in range(1, n):
          b2 = b2 + x[i] * y[i]

      # Lastly we left multiply by the inverse of A and get out answers for a and b
      detA = a11 * a22 - a12 * a21
      b = (b1 * a22 - b2 * a12) / detA
      a = (b2 * a11 - b1 * a21) / detA
      return a, b
