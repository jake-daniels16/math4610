**Module Name:** explicitEuler.py

**Author:** Jake Daniels

**Language:** Python

**Description/Purpose:** Approximate the solution to an ordinary differential equation using an algorithm.

**Input:** The user will need to input a function, f, and initial function value x0, and an interval t0 and T,
as well as an n value which signifies how many times we want to divide our interval.

**Output:** The function will return two vectors, one for t values and one for x values (t is our independent
variable and x dependent).

**Usage/Example:** I used my code from which can be found in another page, titled Logistic Equation and wrote this code to test it:

  tApprox1, xApprox1 = logisticEquation(0.2, 0.0005, 10.0)
  plt.plot(tApprox1, xApprox1, color='red')

Which outputted a graph that can be seen in my Homework Task 4

**Implementation/Code:** The following is code for explicitEuler.py

  import numpy as np
  import matplotlib.pyplot as plt

  def explicitEuler(f, x0, t0, T, n):

      # Here is where we calculate the amount we change out t value for each approx
      h = (T - t0) / n

      # Initialize our f0 value so we don't recalculate it every loop
      f0 = f(t0, x0)

      # Initialize our t and x vectors and append the initial values
      tval = []
      xval = []
      tval.append(t0)
      xval.append(x0)

      # Loop over however many times we split up our interval
      for i in range(1, n):

          # Evaluate our first approximation and save it as x0 for the next loop
          x1 = x0 + h * f0
          x0 = x1

          # Change our t value by moving it h amount to the right and append both new values
          t0 = t0 + h
          tval.append(t0)
          xval.append(x0)

          # Calculate new f0
          f0 = f(t0, x0)

      # return the two vectors
      return tval, xval
