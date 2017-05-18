#!/bin/python

import sys


g = int(raw_input().strip())
for a0 in xrange(g):
    n = int(raw_input().strip())
    sequence = map(int, raw_input().strip().split(' '))
    # If Alice wins, print 'Alice' on a new line; otherwise, print 'Bob'
    ans = 0
    zeros = 0
    for i in range(n):
        if sequence[i] == 0:
            zeros += 1
        else:
            if i > 0 and i < n - 1 and sequence[i - 1] == 0 and sequence[i + 1] == 0:
                ans += 1
            else:
                if zeros > 2:
                    ans += zeros
                zeros = 0
    if zeros > 2:
        ans += zeros
    if ans % 2 == 0:
        print('Bob')
    else:
        print('Alice')
