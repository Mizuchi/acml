#!/usr/bin/env python3

import os
import glob
from subprocess import call

l = glob.glob("*.cpp")

for i in l:
    print("Testing " + i)
    ret = call(["g++", i, "-o", "/tmp/ACMLTEST"])
    assert ret == 0
    ret = os.system("/tmp/ACMLTEST > /tmp/"+i)
    assert ret == 0
