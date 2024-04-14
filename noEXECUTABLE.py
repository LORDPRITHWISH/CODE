import os
import sys
import shutil

def layer(pth):
    home=os.listdir(pth)
    for i in home:
        if os.path.isdir(pth+i):
            layer(pth+i+'/')
        elif os.path.isfile(pth+i) and i.endswith('.exe') :
            os.remove(pth+i)

layer('./')
