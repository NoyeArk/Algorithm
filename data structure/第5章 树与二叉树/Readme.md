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
## 5.3 二叉树的遍历

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

## 5.4 线索二叉树

### 5.4.1 基础概念

传统的二叉树中仅能体现一种父子关系，不能得到结点在遍历中的前驱或后继。在有n个结点的二叉链表中必定有n+1个空链域，能否利用这些空指针域来存储其前驱或后继的指针？

**线索**：指向前驱或后继结点的指针
**线索二叉树**：加上线索的二叉链表表示的二叉树，可以加快查找结点前驱和后继的速度
**线索化**：对二叉树按某种遍历次序使其变为线索二叉树的过程

**二叉树的二叉线索存储表示**
``` C++
// Link==0:指针,Thread==1:线索
typedef enum {Link, Thread} PointerTag;  

typedef struct BiThrNode
{
    TElemType data;
    struct BiThtNode *lchild, *rchild;                            
    PointerTag LTag, Rtag;
}BiTreeNode, *BiThrTree;  
```

### 5.4.2 中序线索二叉树的构造

对普通二叉树以某种次序遍历使其成为线索二叉树的过程就叫做线索化。因为前驱和后继结点只有在二叉树的遍历过程中才能得到，所以线索化的具体过程就是在二叉树的遍历中修改空指针。

线索二叉树分为前序线索二叉树、中序线索二叉树和后续线索二叉树。

#### 算法思想

1. 指针 p 指向根节点，pre 初始化为空，pre 永远指向 p 的前驱。
2. 若 p 非空，则冲入一下操作：
   - 中序遍历线索化 p 的左子树。（递归）
   - 若 p 的左子树为空，则给 p 加上左线索，即 p.ltag = true，p 的左子树指针指向 pre(前驱)，即 p.lchild = pre；否则令 p.ltag = false。
   - 若 pre非空，则判断如果 pre 的右子树为空，给 pre 加上右线索，即 pre.rtag = true，pre 的右孩子指针指向 p (后继)，即 pre.rchild = p；否则令 pre.rtag = false。
   - p 赋值给 pre，p 转向 p 的右子树。
   - 中序遍历线索化 p 的右子树。（递归）
3. 处理最后一个节点，令其后继为空，即 pre.rchild = NULL；pre.rtag = true。

#### 算法过程
![alt text](https://img-blog.csdnimg.cn/dea7570fc7334e52955c5e2f8f9e93d4.gif)

#### 代码实现
``` C++
void in_thread(ThreadTree& p, ThreadTree& pre)
{
	if (p) 
	{
		// 递归 线索化左子树
		in_thread(p->lchild);
		if (p->lchild == NULL) 
		{
			// 建立前驱线索
		    p->ltag = true;
		    p->lchild = pre;
		} 
		else p->ltag = false;

		if (pre != NULL && pre->rchild == NULL) 
		{
			// 建立前驱结点的后继线索
			pre->rtag = true;
			pre->rchild = p;
		}
		// 标记当前结点为刚刚访问过的结点
		pre = p;
		// 递归 线索化右子树
		InThread(p->rchild);
	}
}

void CreateInThread(Btree &T) {
    pre = nullptr;
	// 非空二叉树 线索化
    if (T) 
	{
        InThread(T, pre);
		// 处理遍历的最后一个结点
        pre->rtag = true;
        pre->rchild = nullptr;
    }
}
```
---
## 5.5 树、森林

### 5.5.1 树的存储结构

#### 双亲表示法

定义结构数组存放树的结点，每个结点含两个域：

- 数据域：存放结点本身信息
- 双亲域：指示本结点的双亲结点在数组中位置

**特点：**
- 对于实现求双亲操作很方便，时间复杂度为O(1)
- 对于求某结点的孩子结点的操作，则需要询整个数组
- 这种存储方式不能直接反映各兄弟结点之间的关系，所以实现求兄弟的操作也比较困难

![alt text](https://img-blog.csdnimg.cn/20200629103413543.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzNDAz,size_10,color_FFFFFF,t_70)

#### 孩子表示法

把每个结点的孩子结点排列起来， 以单链表作存储结构，则 n 个结点有 n 个孩子链表，如果是叶子结点则此单链表为空。然后 n 个头指针又组成一个线性表，采用顺序存储结构，存放进一个一维数组中，如图所示：

![alt text](https://img-blog.csdnimg.cn/20190528230933949.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MTk2ODc5,size_16,color_FFFFFF,t_70)

#### 孩子兄弟表示法

对于树这样的层级结构来说，只研究结点的兄弟是不行的，我们观察后发现，任意一棵树， 它的结点的第一个孩子如果存在就是唯一的，它的右兄弟如果存在也是唯一的。 因此，我们设置两个指针，分别指向该结点的第一个孩子和此结点的右兄弟。

![alt text](https://img-blog.csdnimg.cn/20190528232227915.png)

其中 data 是数据域，自firstchild 为指针域，存储该结点的第一个孩子结点的存储地址，rightsib 是指针域，存储该结点的右兄弟结点的存储地址。

![alt text](https://img-blog.csdnimg.cn/20190528232326501.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MTk2ODc5,size_16,color_FFFFFF,t_70)

``` C++
typedef struct CSNode
{
	ElemType data;
	struct CSNode *firstChild，*nextSibling;
}CSNode, *CSTree;
```
**特点：**
- 存储方式比较灵活，可以方便地实现树转换为二叉树的操作，易于查找结点的孩子和兄弟等
- 从当前结点查找其双亲结点比较麻烦

<!-- ![alt text] -->
