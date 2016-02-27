#!/usr/bin/env python
# python q1.py <input file>
import os
import sys
import math
import matplotlib.pyplot as plt

print "HW3-Q1: implement me - don't worry about output format"

# Sample plot
plt.plot([1, 2, 3, 4], [1, 4, 9, 16], label='CLOSE THIS window, to proceed')
plt.title('CLOSE this window, to proceed with the demo')
plt.legend(loc='upper right')
plt.xlabel('Sample x label')
plt.ylabel('Sample y label')
print "     (and kill the plotting window, to proceed)"
plt.show()   # this is BLOCKING the rest of the execution - sigh!
