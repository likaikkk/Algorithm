# 并查集(Union-find Sets)

![](http://oi-wiki.com/ds/images/disjoint-set.svg)

## 引入

**并查集**是一种用于**管理元素所属集合**的数据结构，实现为一个森林，其中每棵树表示一个集合，树中的节点表示对应集合中的元素。

它主要用于处理一些不相交集合的 **合并问题** 。一些常见的用途有 **求连通子图、求最小生成树的 Kruskal 算法和求最近公共祖先(LCA)** 等。

顾名思义，并查集支持两种操作：

- 合并（Union）：合并两个元素所属集合（合并对应的树）
- 查询（Find）：查询某个元素所属集合（查询对应的树的根节点），这可以用于判断两个元素是否属于同一集合

并查集在经过修改后可以支持单个元素的删除、移动；使用动态开点线段树还可以实现可持久化并查集。

## 初始化

> 初始时，每个元素都位于一个单独的集合，表示为一棵只有根节点的树。方便起见，我们将根节点的父亲设为自己。

```cpp
UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0;i < n;i++) {
            parent[i] = i;//Initially, each node is its own root node
        }
    }

```

## 查询

> 我们需要沿着树向上移动，直到找到根节点,未进行路径压缩。

![](http://oi-wiki.com/ds/images/disjoint-set-find.svg)

```cpp
int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return find[parent[x]];
    }
```

## 路径压缩

> 查询过程中经过的每个元素都属于该集合，我们可以将其直接连到根节点以加快后续查询。
> ![](http://oi-wiki.com/ds/images/disjoint-set-compress.svg)

```cpp
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);//Use path compression optimization
    }
    return parent[x];
}
```

## 合并

> 要合并两棵树，我们只需要将一棵树的根节点连到另一棵树的根节点。

![](http://oi-wiki.com/ds/images/disjoint-set-merge.svg)

```cpp
bool unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);

    if (root_x == root_y) {
        return false;
    }

    if (rank[root_x] < rank[root_y])
        parent[root_x] = root_y;
    else if (rank[root_x] > rank[root_y])
        parent[root_y] = root_x;
    else {
        parent[root_y] = root_x;
        rank[root_x]++;
    }

    return true;
}
```

全部代码见：[\_04_UnionFindSets.cpp]()

## 例题：

问题描述：

有一个城市，城市中的居民被编号为 1 到 N。每个居民属于一个小组。每当两个居民成为朋友时，它们所在的小组会合并成一个大的小组。现在，给定 M 个操作，操作分为两种类型：

合并操作：合并两个居民所在的小组。
查询操作：查询两个居民是否属于同一个小组。
编写一个程序，根据给定的操作，判断每个查询操作的结果。

输入：

第一行包含两个整数 N 和 M，表示居民的数量和操作的数量。
接下来的 M 行，每行描述一个操作。操作以以下两种格式之一出现：
"1 a b"：表示将居民 a 和居民 b 合并到同一个小组中。
"2 a b"：表示查询是否居民 a 和居民 b 属于同一个小组。
输出：

对于每个查询操作（类型 2），如果两个居民属于同一个小组，则输出 "YES"，否则输出 "NO"。

示例输入和输出：

输入：

```
5 6
1 1 2
1 2 3
1 4 5
2 1 3
2 2 4
2 1 5
```

输出：

```
NO
YES
YES
```

[\_05_Friend.cpp](E:\Programming\Notes\Algorithm\Code_05_Friend.cpp)
