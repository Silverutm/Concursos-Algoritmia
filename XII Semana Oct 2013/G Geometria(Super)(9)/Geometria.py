#! /usr/bin/env python

PI = 3.141592653589793

while True:
    try:
        R = float( raw_input() )
        print "%.4f" % (R*R*PI)
        print "%.4f" % (R*R*2.0)
    except EOFError:
        break
