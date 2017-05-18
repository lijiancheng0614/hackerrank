# Week of Code 31

https://www.hackerrank.com/contests/w31/challenges

## Beautiful Word

给定一个字符串，判断是否有连续的两个字母都是元音字母或相同。

## Accurate Sorting

给定一个排列，判断是否能只交换相邻且相差为1的数字使其升序。

## Zero-One Game

博弈游戏：给定01序列每次删掉相邻两侧都是$0$的数（最左侧与最右侧不能删除），问必胜是先手还是后手。

## Spanning Tree Fraction

给定一个连通图，边上有权值$(a_i, b_i)$，求$\frac{\sum_{i \in T} a_i}{\sum_{i \in T} b_i}$值最大的最小生成树$T$。

## Colliding Circles

给定$n$个圆，每秒两圆可以合并为半径为两圆半径之和的圆，求$k$秒后所有圆的面积之和的期望。

## Nominating Group Leaders

给定$n$个$0$到$n - 1$之间的数，进行若干查询：求区间$[l, r]$出现次数为$x$的最小的数。

## Split Plane

给定$n$条线段，求分割的连通块数。


---

## Report

Beautiful Word: 模拟

Accurate Sorting: 若存在$i$使得$|i - a[i]| > 1$则不能。

Zero-One Game: 博弈。若连续$0$且长度至少为3的所有子序列长度之和与$010$的子序列个数之和能模2，则后手胜。

Spanning Tree Fraction: 01分数规划+最小生成树。

Colliding Circles: DP或数学计算。

Nominating Group Leaders: 莫队算法+分块。

Split Plane: 几何+线段树+并查集。平面图的欧拉公式。
