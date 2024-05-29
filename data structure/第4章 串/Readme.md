# 第4章 串

## 4.1 串的存储

### 4.1.1 定长顺序存储表示

``` C++
#define MAXSTRING 255  // 用户可在255以内定义最大串长
typedef unsigned char SString [ MAXSTRLEN +1 ];	
```

### 4.1.2 堆分配存储表示

存储空间是在程序执行过程中动态分配得到的，在堆中使用malloc函数和free函数完成动态存储管理。

``` C++
typedef struct
{
	char *Ch;    // 若是非空串，则按串长分配存储区，否则ch为NULL
	int Length;  // 串长度
}HString;
```

### 4.1.3 块链存储表示

类似于线性表的链式存储结构，也可采用链表方式存储串值。

每个结点既可放一个字符，也可以存放多个字符，每个结点称为**块**，整个链表称为**块链结构**。

**块链的效率：**

- 每个结点中数据域越大，效率越高。

$$
	存储密度 = \frac{串所占的存储位}{实际分配的存储位}
$$

``` C++
#define CHUNKSIZE 80  // 块大小
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk *Next;
}Chunk;
typedef struct
{
	Chunk *Head, *Tail;	 // 头指针和尾指针
	int Length;              //串的长度
}LString;
```
---
## 4.2 串的模式匹配

### 4.2.1 简单的模式匹配算法

子串的定位操作通常称作串的模式匹配（其中T被称模式串），是各种串处理系统中最重要的操作之一。

#### 基本思想
1. 从主串S的第一个字符起和模式的第一个字符比较之
   - 若相等，则继续逐个比较后续字符
   - 否则从主串的下一个字符起再重新和模式的字符比较之
2. 依次类推，直至模式T中的每个字符依次和主串S中的一个连续的字符序列相等，则称匹配成功

``` C++
int BF(string S, string T)
{
	int i = 0, j = 0;
	while (i < S.size() && j < T.size())
	{
		if (S[i] == T[j]) i ++, j ++;
		else i = i - j + 2, j = 0;
	}
	if (j >= T.size()) return i - T.size();
	return 0;
}
```
#### 算法演示
![alt text](https://pic2.zhimg.com/80/v2-7f0ced6c05f25a0ddc48627012450fbd_1440w.webp)

#### 性能分析

- **最好时间复杂度**：O(T.size() + S.size())
- **最坏时间复杂度**：O(T.size() * S.size())

### 4.2.2 KMP算法

KMP算法的改进在于：每一趟匹配过程中出现字符比较不等时，不需要回朔指针 i ，要利用已经“部分匹配”结果，调整指针 j ，即将模式向右滑动尽可能远的一段距离，来提高算法效率。

KMP算法匹配过程示意如下：

![alt text](https://pic2.zhimg.com/80/v2-e6f52632d9776ca67233d0b81504c425_1440w.webp)

