###########################################################
# Author: yourName
# Date: Feb. 2016
# Usage:
#	     python eliasg.py <someNumber>
#     should return the elias-gamma code for that number
#     (currently, it returns '1', no matter what.
###########################################################

import sys
import math

if len(sys.argv) != 2:
    sys.exit("usage: eliasg.py input")

input = int(sys.argv[1])

count = 0
i = input

while (i != 0):
    count += 1
    i = i >> 1

ret = '0'
ret = ret * (count - 1)

i = input
ret_2 = ''

while (i != 0):
    ret_2 += str(i & 0x01)
    i = i >> 1
print ret + ret_2[::-1]
