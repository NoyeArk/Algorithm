# 第三讲 搜索与图论
## 讲解内容
包括DFS，BFS，树与图的深度优先遍历，树与图的广度优先遍历，拓扑排序，Dijkstra，bellman-ford，spfa，Floyd，Prim，Kruskal，染色法判定二分图，匈牙利算法等内容。
## 思维导图
- 单源最短路
    1. 所有边权都是正数
        1. 朴素Dijkstra算法 O(n²)
        2. 堆优化版的Dijkstra算法 O(mlogn)
    2. 存在负权边
        1. Bellman-Ford O(nm)
        2. SPFA 一般O(m)，最坏O(nm)
- 多源最短路
    1. Floyd算法 O(n<sup>3</sup>)