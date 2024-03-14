def outfunc(a=0):
    print("This is outfunc")
    c=a
    def innerfunc():
        nonlocal c
        c+=1
        print("This is innerfunc with c=",c)
    return innerfunc

f=outfunc(100)
f()
f()
f()
f()
f()
f()
f()
f()
f()
f()
f()
f()
f()
