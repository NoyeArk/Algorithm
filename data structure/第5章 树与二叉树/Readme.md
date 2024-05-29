# 第5章 树与二叉树

## 5.2 二叉树的概念

### 5.2.2 二叉树的存储结构

#### 顺序存储

二叉树的顺序存储结构就是用一维数组存储二叉树中的结点，并且结点的存储位置，也就是数组的下标要能体现结点之间的逻辑关系，比如双亲与孩子之间的关系，左右兄弟之间的关系等。

当然对于一般的二叉树，尽管层序编号不能反映逻辑关系，但是可以将其按完全二叉树编号，只不过，把存在的结点设置为“^”而已。如图中，注意浅色结点表示不存在。

![alt text](https://img-blog.csdnimg.cn/20200620132130300.png#pic_center)

**特点：**
- 结点间关系蕴含在其存储位置中
- 浪费空间，适于存满二叉树和完全二叉树

#### 链式存储

二叉树每个结点最多有两个孩子，所以为他设计一个数据域和两个指针域是比较自然的想法，我们称这样的链表叫做二叉链表。


``` C++
// 二叉树的二叉链表结点结构定义
typedef struct BiNode
{
	TElemType data;    				 // 结点数据
	struct BiTNode *lchild,*rchild;  // 左右孩子指针
}
```

![alt text](https://img-blog.csdnimg.cn/20200620133242906.png#pic_center)

另外还有一种三叉链表，定义如下所示。
``` C++
typedef struct Node
{   
	Elemtype data;
	struct Node *lchild, *rchild, *parent;  // parent指针指向父结点
};
```
---
## 5.3 二叉树的遍历和线索二叉树

### 5.3.1 二叉树的递归遍历

**遍历**：按一定规律走遍树的各个顶点，且使每一顶点仅被访问一次，即找一个完整而有规律的走法，以得到树中所有结点的一个线性排列。

二叉树的遍历可以分解为：访问根，遍历左子树和遍历右子树。

#### 先序遍历

##### 算法思想
根节点→左子树→右子树

``` C++
void pre_order(BiTree T)
{
	if (T != NULL)
	{
		visit(T);
		pre_order(T.lchild);
		pre_order(T.rchild);
	}
}
```
##### 算法图解
![alt text](https://developer.qcloudimg.com/http-save/yehe-admin/476cc2797c949cbad013db8f940786b7.png)

#### 中序遍历

##### 算法思想
左子树→根节点→右子树

``` C++
void in_order(BiTree T)
{
	if (T != NULL)
	{
		in_order(T.lchild);
		visit(T);
		in_order(T.rchild);
	}
}
```
##### 算法图解
![alt text](https://developer.qcloudimg.com/http-save/yehe-admin/4e72e965f0533784674e654a1c7dab63.png)

#### 后序遍历

##### 算法思想
左子树→右子树→根节点

``` C++
void post_order(BiTree T)
{
	if (T != NULL)
	{
		post_order(T.lchild);
		post_order(T.rchild);
		visit(T);
	}
}
```
##### 算法图解
![alt text](https://developer.qcloudimg.com/http-save/yehe-admin/23657993645fa486e5cb3c656c11128f.png)

#### 性能分析

- **时间复杂度**：上述三种遍历方式，只是访问根节点的顺序不同，不管采用哪种遍历方法，每个结点都只访问一次，所以时间复杂度均为O(n)
- **空间复杂度**：递归遍历中，栈深刚好是树的深度，所以最坏情况下，空间复杂度为O(n)

### 5.3.2 二叉树的非递归遍历

树的递归过程本质上实对栈的操作过程，因此可以直接通过对栈的读操作，来把递归算法写为非递归算法。

#### 先序遍历代码实现
``` C++
int stk[N], tt = -1;
void in_order(BiTree T)
{
	auto p = T;
	while (p || tt)
	{
		if (p)
		{
			visit(p);
			stk[++ tt] = p;
			// 一路走向最左儿子
			p = p.lchild;
		}
		else
		{
			auto t = stk[tt --];
			t = t.rchild;
		}
	}
}
```

#### 中序遍历代码实现
``` C++
int stk[N], tt = -1;
void in_order(BiTree T)
{
	auto p = T;
	while (p || tt)
	{
		if (p)
		{
			stk[++ tt] = p;
			// 一路走向最左儿子
			p = p.lchild;
		}
		else
		{
			auto t = stk[tt --];
			visit(t);
			t = t.rchild;
		}
	}
}
```

### 5.3.3 二叉树的层次遍历

**层次遍历**：从上到下、从左到右访问各结点。

![alt text](https://img-blog.csdnimg.cn/5461810bfdb441ba87d2c78bc3f3e252.png)

进行层次遍历，需要借助一个队列：
- 先将二叉树根节点入队，然后出队，访问出队结点
- 左子树入队
- 右子树入队

#### 代码实现：

``` C++
int q[N], hh, tt = -1;
void level_order(BiTree T)
{
	q[++ tt] = T;
	while (hh <= tt)
	{
		auto t = q[hh ++];
		visit(t);
		if (t.lchild != NULL) q[++ tt] = t.lchild;
		if (t.rchild != NULL) q[++ tt] = t.rchild;
	}
}
```

<!-- ![alt text] -->
