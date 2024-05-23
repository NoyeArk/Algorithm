# 第6章 图论

## 6.1 图的存储

图的存储结构至少要保存两类信息：	

1. 顶点的数据
2. 顶点间的关系

如何表示顶点间的关系？

### 6.1.1 邻接矩阵

图的邻接矩阵(Adjacency Matrix) 存储方式是用两个数组来表示图。一个一维数组存储图中顶点信息，一个二维数组(称为邻接矩阵)存储图中的边或弧的信息。

设图 G 有 n 个顶点，则邻接矩阵 A 是一个n ∗ n的方阵，定义为:

![alt text](https://img-blog.csdnimg.cn/20210301095908432.png#pic_center)

下图是一个无向图和它的邻接矩阵：

![alt text](https://img-blog.csdnimg.cn/202103011006555.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1JlYWxfRm9vbF8=,size_16,color_FFFFFF,t_70#pic_center)

可以看出：
1. 无向图的邻接矩阵一定是一个对称矩阵(即从矩阵的左上角到右下角的主对角线为轴，右上角的元与左下角相对应的元全都是相等的)。 因此，在实际存储邻接矩阵时只需存储上(或下)三角矩阵的元素。
2. 对于无向图，邻接矩阵的第i行(或第i列)非零元素(或非∞元素)的个数正好是第i个顶点的度。
3. 有向图中：
   1. 顶点Vi的出度是A中第i行元素之和
   2. 顶点Vi的入度是A中第i列元素之和

   
**邻接矩阵存储适用于稠密图。**

### 6.1.2 邻接表

当一个图为稀疏图时（边数相对顶点较少），使用邻接矩阵法显然要浪费大量的存储空间，如下图所示：

![alt text](https://img-blog.csdnimg.cn/20210301113238489.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1JlYWxfRm9vbF8=,size_16,color_FFFFFF,t_70#pic_center)

而图的邻接表法结合了顺序存储和链式存储方法，大大减少了这种不必要的浪费。

邻接表类似于树的孩子表示法，如果能把图中任一个顶点的所有邻接点都表示出来，也就可以表示图。

实现：为图中每个顶点建立一个单链表，第i个单链表中的结点表示依附于顶点Vi的边（有向图中指以Vi为尾的弧）。代码见[邻接表.cpp](图的存储/邻接表.cpp)

无向图的邻接表的实例如下图所示：

![alt text](https://img-blog.csdnimg.cn/20210301165232511.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1JlYWxfRm9vbF8=,size_16,color_FFFFFF,t_70#pic_center)

**邻接表表示的特点：**
1. 无向图中顶点Vi的度为第i个单链表中的结点数
2. 有向图中
   1. 顶点Vi的出度为第i个单链表中的结点个数
   2. 顶点Vi的入度为整个单链表中邻接点域值是i的结点个数
3. 逆邻接表：有向图中对每个结点建立以Vi为头的弧的单链表

### 6.1.3 十字链表

十字链表是**有向图**的一种链式存储结构。代码见[十字链表.cpp](图的存储/十字链表.cpp)

对于有向图来说，邻接表是有缺陷的。关心了出度问题，想了解入度就必须要遍历整个图才能知道，反之，逆邻接表解决了入度却不了解出度的情况。有没有可能把邻接表与逆邻接表结合起来呢?答案是肯定的，就是把它们整合在一起。这就是我们现在要介绍的有向图的一种存储方法：十字链表(Orthogonal List)。

重新定义顶点表结点结构如下表所示。

![alt text](https://img-blog.csdnimg.cn/20210301175445875.png#pic_center)

其中firstin表示入边表头指针，指向该顶点的入边表中第一个结点，firstout 表示出边表头指针，指向该顶点的出边表中的第一个结点。

重新定义的边表结点结构如下表所示。

![alt text](https://img-blog.csdnimg.cn/20210301175546226.png#pic_center)

其中 tailvex 是指弧起点在顶点表的下标，headvex 是指弧终点在顶点表中的下标，headlink 是指入边表指针域，指向终点相同的下一条边，taillink 是指边表指针域，指向起点相同的下一条边。如果是网，还可以再增加一个 weight 域来存储权值。

**举例如下：**

![alt text](https://img-blog.csdnimg.cn/20210301180237656.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1JlYWxfRm9vbF8=,size_16,color_FFFFFF,t_70#pic_center)

十字链表的好处就是因为把邻接表和逆邻接表整合在了一起，这样既容易找到以V~1~为尾的弧，也容易找到以V~1~为头的弧，因而容易求得顶点的出度和入度。而且它除了结构复杂一点外，其实创建图算法的时间复杂度是和邻接表相同的，因此，在有向图的应用中，十字链表是非常好的数据结构模型。

### 6.1.4 邻接多重表

邻接多重表是**无向图**的另一种链式存储结构。

在邻接表中，容易求得顶点和边的各种信息，但在邻接表中求两个顶点之间是否存在边而对边执行删除等操作时，需要分别在两个顶点的边表中遍历，效率较低。

比如下图中，若要删除左图的（v~0~, v~2~）这条边，需要对邻接表结构中右边表的阴影两个结点进行删除操作，显然这是比较烦琐的。

![alt text](https://img-blog.csdnimg.cn/20210301182203109.png#pic_center)

重新定义的边表结点结构如下表所示。

![alt text](https://img-blog.csdnimg.cn/20210301183315496.png#pic_center)
其中 ivex 和 jvex 是与某条边依附的两个顶点在顶点表中下标。ilink 指向依附顶点 ivex 的下一条边，jlink 指向依附顶点 jvex 的下一条边。这就是邻接多重表结构。

每个顶点也用一一个结点表示，它由如下所示的两个域组成。

![alt text](https://img-blog.csdnimg.cn/20210301183423578.png#pic_center)
其中，data 域存储该顶点的相关信息，firstedge 域指示第一条依附于该顶点的边。

**举例如下：**

![alt text](https://img-blog.csdnimg.cn/20210301185220315.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1JlYWxfRm9vbF8=,size_16,color_FFFFFF,t_70#pic_center)

---
<!-- ![alt text]
![alt text]
![alt text] -->