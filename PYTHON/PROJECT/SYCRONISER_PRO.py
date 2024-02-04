import os
import time
import sys

# Set the default encoding to utf-8
sys.stdout.reconfigure(encoding='utf-8')

asd="FF"
LOC = r''
fl=[]

content =os.listdir(LOC)
for i in content :
    fipo=os.path.join(LOC,i)
    cti = os.path.getctime(fipo)
    fl.append((cti,fipo,i))
fl.sort()
l=len(fl)
spa=0
while l>0 :
    l=l//10
    spa+=1
n=0
for i in fl :
    n+=1
    os.rename(i[1],f'{LOC}\\{n:0>{spa}}-{i[2]}')
print('DONE BRO')