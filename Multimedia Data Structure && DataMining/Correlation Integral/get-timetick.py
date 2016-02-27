#!/usr/bin/env python

###########################################################
# Author: Christos Faloutsos
# Date: Feb. 2016
# Usage:
#	get-timetick.py filename timetick
# gets all the
#    x y z t
# lines, for the specified timetick
###########################################################

import sys
import math
import matplotlib.pyplot as plt

def L1(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) + abs(p1[2] - p2[2])

def L2(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2 + (p1[2] - p2[2])**2)

def D2DimensionNavieL2(data=[]):
    ret_x = []
    ret_y = []
    r = 0.0
    for i in range(0, 400):
        ret_x.append(r)
        count = 0
        for p in data:
            for q in data:
                if (L2(p, q) <= r):
                    count += 1
        ret_y.append(count)
        r += 0.01
    return ret_x, ret_y

def D2DimensionNavieL1(data=[]):
    ret_x = []
    ret_y = []
    r = 0.0
    for i in range(0, 400):
        ret_x.append(r)
        count = 0
        for p in data:
            for q in data:
                if (L1(p, q) <= r):
                    count += 1
        ret_y.append(count)
        r += 0.01
    return ret_x, ret_y


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print "USAGE: get-timetick.py <fname> <integer>"
        sys.exit("wrong number of arguments")

    filename = sys.argv[1]
    timetick = int( sys.argv[2])
    LD = int(sys.argv[3])

    infile = open(filename, 'r')

    data = []
    for line in infile.xreadlines():
        columns = line.split(' ') # split on blank
        timestamp = int( columns[3] )
        if (len(columns) != 4 ):
            print "ERROR: input line has ", len(columns), " instead of 4 columns"
            sys.exit()
        if timetick == timestamp:
            data.append([float(columns[0]), float(columns[1]), float(columns[2])])

    infile.close()
    x_axis = []
    y_axis = []
    if (LD == 0):
        x_axis, y_axis = D2DimensionNavieL1(data)

    if (LD == 1):
        x_axis, y_axis = D2DimensionNavieL2(data)
        
    plt.plot(x_axis, y_axis)
    print x_axis
    print y_axis
    plt.show()
