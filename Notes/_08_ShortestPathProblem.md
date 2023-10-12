# 最短路

> [视频连接](https://www.bilibili.com/video/BV1aA4y197FP/?spm_id_from=333.337.search-card.all.click&vd_source=43c7ed6468d0a8ef142fdf57a192e4ce)

## Dijkstra 算法

### 适用范围

> 求**无负权边**的**单源最短路**。
>
> 【单源最短路】从某一点出发，到其他所有点的最短路径。

### 性质

> 基于顶点求单源最短路，n 个顶点，m 条边，算法的时间复杂度为$O(n^2)$。非常适合点少边多的稠密图。
>
> 利用`贪心策略`实现
>
> 【Dijkstra】优先队列版-堆优化

### 步骤

1. 设一个集合，保存已经找到最短路的顶点，先将起点加入集合。
2. 将起点到所有点的距离存在 dis 数组里，不能直接到达的点（起点与该点无边）存为无穷大。
3. 在 dis 数组中找一个最小值，当前值一定是起点到该点的最短路，将该点加入集合。
4. 遍历其他的点，如果它们通过这个最短的点作为中转，比源点直接到达短，就替换这些顶点到源点的 dis 值（**松弛操作**）`if dis[i]>dis[min]+map[min,i];dis[i]=dis[min]+map[min,i];`
5. 又从 dis 中找出最小值，重复上面的操作，直到 T 集合包含所有的顶点。

### 实现

1. 向前星
2. $O(n^2)$暴力做法

```cpp
struct edge {
  int v, w;
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];

void dijkstra(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    int u = 0, mind = 0x3f3f3f3f;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
    vis[u] = true;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
    }
  }
}
```

3. $O(mlogm)$的优先队列做法

```cpp
        struct edge {
  int v, w;
};

struct node {
  int dis, u;

  bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;

void dijkstra(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}
```

## Bellman-Ford 算法

### 适用范围

> 可以求**带负权边**的图的**单源最短路**。并且可以**判断图是否存在负环**，存在负环的图求最短路是没有意义的，因为它的路径权会无限缩小。
>
> 【Bellman-Ford】队列优化-SPFA

## Floyd 算法

### 适用范围

> 可以求**带负权边**，但不带负环图的**多源最短路**。
>
> 【多元最短路】整个图的每个点到其他所有点的最短路。

> 是用来求任意两个结点之间的最短路的。
> 复杂度比较高，但是常数小，容易实现（只有三个`for`）
> 适用于任何图，不管有向无向，边权正负，但是最短路必须存在。（不能有个负环）

### 实现
