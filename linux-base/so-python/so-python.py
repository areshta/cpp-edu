from ctypes import *
cdll.LoadLibrary("./lib/libctest.so")

print ("so-python example")

libctest.input(a,b)

print( a, b)
