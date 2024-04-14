import numpy as np
from time import perf_counter as pc
a=np.arange(12)
print(a)
print(a.shape) #inspect the array, (12, ) this is one dimensional array with 12 elements
a.shape=3, 4 #change the shape of the matrix in 3 lines with 4 columsn, 3 dimensions with 4 elements for each
print(a)
a.transpose() #Create a new array by transposing (swapping columns with rows).
# print(a)
# print(a[0])
# print(a[:, 1])
b=np.array([1508181.34597761, 267640.55257131, 2283280.22186973])
b.shape=3, 3
print(b)
t0=pc()
b/=3
print(pc()-t0)
