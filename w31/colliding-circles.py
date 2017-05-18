#!/bin/python

import sys
from math import pi
from decimal import Decimal

def f(n, k):
    if k <= 1:
        if n == 1:
            return 1
        return 2.0 / n / (n - 1)
    if k == 2:
        return 4.0 / ((n - 1) ** 2)
    ans = 1
    for i in range(1, k):
        ans = ans * (n - i + 1) / i
    ans = ans * k * 4
    ans = Decimal(ans)
    for i in range(2, k - 1):
        ans = ans * (k - i + 1) / (n - i)
    ans = ans / n / (n - k + 1) / ((n - 1) ** 2)
    return ans

n, k = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split(' '))
ans = 0
if k > 0:
    s = 0
    for i in range(n):
        s += a[i]
        t += a[i] * a[i]
    ans = s * s - t
    ans = ans * f(n, k)

for i in range(n):
    ans += a[i] ** 2

ans = Decimal(ans) * Decimal(pi)
print("%.10f" % ans)
