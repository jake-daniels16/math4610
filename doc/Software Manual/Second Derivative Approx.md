**Module Name:** secondDerivative.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** This function will compute an approximation of a the second derivative for a given function,
the user will also need to provide an inital value, a value for h, and an exact value (which we use to compute the error
not actually necessary for computing the approximation itself)

**Input:** The user will need to input a function, f, an initial value, x0, an h value, and an exact value of the second
derivative.

**Output:** The function will return a three vectors, one for the h values used, one for the f'' values, and one for the difference
between our approximation and the exact value.

**Usage/Example:** I created the following test function that puts our values into a table:

    def test():
        exact = 16 * (-np.pi ** 3 + 3 * np.pi ** 2 - 1040 * np.pi + 1040) / (np.pi ** 2 + 1040) ** 2
        hVals, fVals, diff = secondDerivative(lambda x: (x - np.pi / 2) * np.tan(x) * np.tan(x) / (x * x + 65), np.pi / 4, 1.0, exact)
        print("h values | approximations | exact | difference")
        for i in range (0, 19):
            print(hVals[i], " | ", fVals[i], " | ", exact, " | ",  diff[i])

    test()

The ouput will look as follows which I have shortened to save space:

    h values | approximations | exact | difference
    1.0  |  0.08888433309385912  |  -0.03235131011796782  |  0.12123564321182695
    ...
    3.814697265625e-06  |  -0.06767797470092773  |  -0.03235131011796782  |  -0.03532666458295992

**Implementation/Code:** The following is code for secondDerivative.py

  import numpy as np

  def secondDerivative(f, x0, h, exact):

      # Here I compute the value of f at the given intial value
      f0 = f(x0)

      # Here I create the three empty vectors that we will be appending values to
      diff = []
      fV = []
      hV = []

      # Here I create a for loop to approximate the second derivative 20 times at smaller h values
      for i in range (1, 20):

          # Append initial h value to out hV vector
          hV.append(h)

          # Save values for f just to the right and left of our initial point
          f1 = f(x0 + h)
          f2 = f(x0 - h)

          # Calculate our approximation
          fval = (f1 - 2 * f0 + f2) / (h * h)

          # Append the approximation and error to their respected vectors
          fV.append(fval)
          diff.append(fval - exact)

          # Decrease our h by a factor of 2 so we get closer to the intitial x0 value
          # and hence a better approximation
          h = h / 2

      # return 3 vectors
      return hV, fV, diff
