# from array import array
# from random import random
# floats=array('d', (random() for i in range(10**7)))
# print(floats[-1])
# fp=open('floats.bin', 'wb')
# floats.tofile(fp)
# fp.close()
# floats2=array('d')
# fp=open('floats.bin', 'rb')
# floats2.fromfile(fp, 10**7)
# fp.close()
from array import array
octets=array('B', range(6)) #typecode 'B' says that is an array of 6 bytes
m1=memoryview(octets)
print(m1.tolist())
m2=m1.cast('B', [2,3]) #matrix 2 lines with 3 elements per each line
m3=m1.cast('B', [3,2])#matrix 3 lines with 2 elements per each line
print(m2.tolist(), '\n', m3.tolist())
m2[0,0]=5
print(octets)