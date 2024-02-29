import time
from numba import njit

@njit
def calculate(x,z):
    a=0;b=0;c=0
    for i in range(x):
        a+=i
        a/=z
    for i in range(x):
        b+=i
        b/=(z+1)
    for i in range(x):
        c+=i
        c/=(z+2)
    return (a,b,c)


t1=time.time()
print(calculate(100000000,2))
t2=time.time()
print("TIME NEEDED IS :  ",t2-t1)


t1=time.time()
print(calculate(1000000000,2))
t2=time.time()

print("TIME NEEDED IS :  ",t2-t1)