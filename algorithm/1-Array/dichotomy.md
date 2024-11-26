# 1 二分介绍

## 1.1 什么是二分法

二分法是一种高效的查找方法，它通过将问题的**搜索范围一分为二**（两边具有明显的区别），迭代地缩小搜索范围，直到找到目标或确定目标不存在。

二分法适用于**有序数据集合**，并且每次迭代可以将搜索范围**缩小一半**。

二分法本质上也是**枚举**，但和暴力枚举不同，二分法利用数据结构的**单调性**减少了很多不必要的枚举，从而极大地提高了效率，一般可以将 $O(n)$ 的枚举优化到 $O(logn)$ 。

常见的二分类型有：

1. 整数二分
2. 浮点二分
3. 二分答案（最常见）

## 1.2 解题步骤

1. 研究并发现数据结构（或答案变量）的**单调性**。
2. 确定最大区间 $[l, r]$ ，确保分界点一定在里面，具体有一些细节：
    - 若以 $r$ 作为答案，那么答案区间在 $[l+1, r]$
    - 若以 $l$ 作为答案，那么答案区间在 $[l, r-1]$
3. **确定check函数**，一般为传入 $mid$ （区间中某个下标），返回 $mid$ 所属区域或返回一个值，当check函数较简单时可以直接判断。
4. 计算中点 $mid=(l+r)/2$ ，用 $check$ 判断该移动 $l$ 或 $r$ 指针，具体移动那个需要根据单调性以及要求的答案来判断。
5. 返回 $l$ 或 $r$ ，根据题意判断。

什么时候使用判断条件 $l \leq r$ ，什么时候使用条件 $l < r$ 取决于在更新区间时的操作，例如题目【】每次更新区间时会划分 $[l, mid - 1)$ 、 $mid$ 和 $(mid, r]$ 这三个部分，所以使用 $l \leq r$ 。

否则使用 $l < r$ 。

---

# 2 整数二分

## 2.1 模板

整数二分就是在一个已有的有序数组上，进行二分查找，一般为找出某个值的位置，或者时找出分界点。这个数组肯定是开的下的，其数组大小一般是在 $10^6$ 以内。

寻找左边界：

```python
l = 0, r = n
while l < r:
    mid = l + r + 1 >> 1
    if check():
        l = mid
    else:
        r = mid - 1
return r
```

寻找右边界：

```python
l = 0, r = n
while l < r:
    mid = l + r >> 1
    if check():
        r = mid
    else:
        l = mid + 1
return r
```

---

# 3 例题

## 3.1 二分查找

1. [704. 二分查找](/leetcode/其他/704.%20二分查找.md)
2. [35. 搜索插入位置](/leetcode/2-热题100/11-二分查找/35.%20搜索插入位置.md)
3. [69. $x$ 的平方根](/leetcode/其他/69.%20x%20的平方根.md)
4. [367. 有效的完全平方数](/leetcode/其他/367.%20有效的完全平方数.md)
5. [540. 有序数组中的单一元素](/leetcode/4-每日一题/540.%20有序数组中的单一元素.md)
6. [744. 寻找比目标字母大的最小字母](/leetcode/其他/744.%20寻找比目标字母大的最小字母.md)
7. [2529. 正整数和负整数的最大计数](/leetcode/其他/2529.%20正整数和负整数的最大计数.md)

## 3.2 二分答案：求最小

## 3.3 二分答案：求最大

1. [275. H 指数 II](/leetcode/其他/275.%20H%20指数%20II.md)
2. [2226. 每个小孩最多能分到多少糖果](/leetcode/其他/2226.%20每个小孩最多能分到多少糖果.md)