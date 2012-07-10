#!/usr/bin/env python3

import os
import glob
from subprocess import call

l = glob.glob("*.cpp")

for i in l:
    print("Compiling " + i)
    ret = call(["g++", i, "-o", "/tmp/ACMLTEST"])
    if ret == 0:
        print('Compile successfully. Run and output to /tmp/'+i[:-3]+'json')
        ret = os.system("/tmp/ACMLTEST > /tmp/"+i[:-3] + 'json')
        if ret == 0:
            print("Finished " + i)
            print("You can verify the output in /tmp/" + i[:-3] + 'json')
        else:
            print("Failed " + i)
