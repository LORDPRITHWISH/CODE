from functools import reduce


a=list(range(1,11))

# a=filter(lambda x: x%2==0,a)

c=reduce(lambda x,y: x+y,a)
d=sum(a)

print(c)
print(d)

# a=(str(i) for i in a)



# # b='-@-'.join(str(i) for i in a)
# b='-@-'.join(a)

# print(b)

