#!/bin/python

import sys

q = int(raw_input().strip())
for a0 in xrange(q):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split(' '))
    # Write Your Code Here
    flag = True
    for i in range(n):
        if abs(i - a[i]) > 1:
            flag = False
            break
    if flag:
        print('Yes')
    else:
        print('No')
