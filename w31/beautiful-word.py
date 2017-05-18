#!/bin/python

import sys

w = raw_input().strip()
# Print 'Yes' if the word is beautiful or 'No' if it is not.
vowels = ['a', 'e', 'i', 'o', 'u', 'y']
n = len(w)
flag = True
for i in range(1, n):
    if w[i] == w[i - 1] or (w[i] in vowels and w[i - 1] in vowels):
        flag = False
        break
if flag:
    print('Yes')
else:
    print('No')
