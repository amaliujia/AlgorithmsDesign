#####################################################
# Author: Di Jin
# Date: Feb. 2016
# USAGE:
#       python ieliasg.py <bitstring>
# to decode it
# Currently, returns a fixed response: 10 20 ...
#####################################################

import sys
import math

if len(sys.argv) != 2:
    sys.exit("usage: ieliasg.py input-bitstring")

input = sys.argv[1]

if len(input) <= 2:
    print "Illegal input"

ret_n = []

count = 0
i = 0
num = 0
while (i < len(input)):
    if (input[i] == "0"):
        count += 1
        i += 1
    elif (input[i] == "1"):
        num = 1
        i += 1
        while (count > 0):
            num = num << 1 | int(input[i])
            count -= 1
            i += 1
        ret_n.append(num)
        num = 0
    else:
        print "Illegal input"

print ret_n
