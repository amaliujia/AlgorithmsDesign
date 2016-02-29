#!/usr/bin/env python

##################################################
# Author: Varshaa Naganathan, Christos Faloutsos
# Date: Feb. 2016
# Usage: python q2.py <source> <target>
##################################################

import sys
import os

def computeLevenshteinDistance(word,entry):
    vowel = ['a', 'e', 'i', 'o', 'u']
    szword = len(word)
    szentry = len(entry)
    distance = [0]*(szword+1)

    for i in range(0,szword+1):
        distance[i] = [0]*(szentry+1)
        distance[i][0] = i

    for j in range(0,szentry+1):
        distance[0][j] = j

    for i in range(1,szword+1):
        for j in range(1,szentry+1):
              if word[i-1] == entry[j-1]:
                  distance[i][j] = distance[i-1][j-1]
                  continue
              min_d = sys.maxint
              min_d = min(min_d, 1 + distance[i][j-1], 1 + distance[i-1][j])
              if word[i-1] in vowel and entry[i-1] in vowel:
                  min_d = min(min_d, 0.1 + distance[i-1][j-1])
              elif word[i-1] not in vowel and entry[i-1] in vowel:
                  min_d = min(min_d, 0.9 + distance[i-1][j-1])
              elif word[i-1] in vowel and entry[i-1] not in vowel:
                  min_d = min(min_d, 0.9 + distance[i-1][j-1])
              else:
                  min_d = min(min_d, 0.5 + distance[i-1][j-1])
              distance[i][j] = min_d

    # print distance
    for i in range(0,szword+1):
        for j in range(0,szentry+1):
            print "%5.2f" % (distance[i][j]),
        print "" # prints a newline

    return distance[szword][szentry]

# Read command line arguments
source = sys.argv[1]
target = sys.argv[2]

distance = computeLevenshteinDistance(source,target)

print "D(%s,%s)=%5.2f\n" % (source, target, distance)
