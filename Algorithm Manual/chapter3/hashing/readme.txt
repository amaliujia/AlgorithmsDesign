Hash function:

H(S) = sum(size * char(S[i]))

size: the size of alphabet on which a given string S is written
char(): the function which map element of give alphabet to a unique integer from 0 to size-1

then we need a number of buckets, use m to mark it. Usually m is enough if m is a large prime not too close to 2^i-1.


