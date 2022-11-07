# Jake Daniels
# Math 4610

def vecAdd(a, b):
    if len(a) != len(b):
        print("Vectors must be the same length")
        return None
    c = []
    for i in range(len(a)):
        c.append(a[i] + b[i])
    return c
