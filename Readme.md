# 机试算法学习
记录各个平台学习算法题的过程，希望能够不断增强自己的算法机试能力。

## 1.由数据范围反推算法复杂度以及算法内容
一般ACM或者笔试题的时间限制是1秒或2秒。
在这种情况下，C++代码中的操作次数控制在10<sup>7</sup>~10<sup>8</sup>为最佳。

下面给出在不同数据范围下，代码的时间复杂度和算法该如何选择：
1. n≤30, 指数级别, dfs+剪枝，状态压缩dp
2. n≤100 => O(n³)，floyd，dp，高斯消元
3. n≤1000 => O(n²)，O(n²logn)，dp，二分，朴素版Dijkstra、朴素版Prim、Bellman-Ford
4. n≤10000 => O(n∗$\sqrt n$)，块状链表、分块、莫队
5. n≤100000 => O(nlogn)，各种sort，线段树、树状数组、set/map、heap、拓扑排序、dijkstra+heap、prim+heap、Kruskal、spfa、求凸包、求半平面交、二分、CDQ分治、整体二分、后缀数组、树链剖分、动态树
6. n≤1000000, 以及常数较小的 O(nlogn)，单调队列、 hash、双指针扫描、BFS、并查集，kmp、AC自动机，常数比较小的 O(nlogn) 的做法：sort、树状数组、heap、dijkstra、spfa
7. n≤10000000 => O(n)，双指针扫描、kmp、AC自动机、线性筛素数
8. n≤10<sup>9</sup> => O($\sqrt n$)，判断质数
9. n≤10<sup>18</sup> => O(logn)，最大公约数，快速幂，数位DP
10. n≤10<sup>1000</sup> => O((logn)²)，高精度加减乘除
11. n≤10<sup>100000</sup> => O(logk×loglogk)，k表示位数，，高精度加减、FFT/NTT

## 2.学习过程

1. Acwing平台算法基础课
2. Acwing平台蓝桥杯每日一题
3. Leetcode平台热题100