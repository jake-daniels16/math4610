# Jake Daniels
# CS1400 - 001
# Assignment ??

import numpy as np
from Methods.dotProduct import dotProduct
from Methods.crossProduct import crossProduct

def tripleProduct(a, b, c):
    if len(a) != 3 or len(b) != 3 or len(c) != 3:
        return "Error: Input vectors must be 3D"
    else:
        return dotProduct(a, crossProduct(b, c))