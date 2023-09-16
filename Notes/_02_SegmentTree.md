# 线段树

## 引入

线段树是算法竞赛中常用来维护`区间信息`的数据结构。

线段树可以再 O(logN)的实践复杂度内实现 **单点修改、区间修改（区间求和、求区间最大值、求区间最小值）** 等操作。

## 线段树

### 1.线段树的基本结构与建树

#### 过程：

线段树将每个长度不为 1 的区间划分成左右两个区间递归求解，把整个线段划分为一个树形结构，通过合并左右两区间信息来求得该区间的信息。这种数据结构可以方便的进行大部分的区间操作。

有个大小为 5 的数组 a={10,11,12,13,14}，要将其转化为线段树，有以下做法：设线段树的根节点编号为 1，用数组 d 来保存我们的线段树，d<sub>i</sub> 用来保存线段树上编号为 i 的节点的值（这里每个节点所维护的值就是这个节点所表示的区间总和）。

我们先给出这棵线段树的形态，如图所示：
![](https://oi-wiki.org/ds/images/segt1.svg)
图中每个节点中用红色字体标明的区间，表示该节点管辖的 a 数组上的位置区间。如 d_1 所管辖的区间就是 [1,5]（a_1,a_2, \cdots ,a_5），即 d_1 所保存的值是 a_1+a_2+ \cdots +a_5，d_1=60 表示的是 a_1+a_2+ \cdots +a_5=60。

通过观察不难发现，d*i 的左儿子节点就是 d*{2\times i}，d*i 的右儿子节点就是 d*{2\times i+1}。如果 d*i 表示的是区间 [s,t]（即 d_i=a_s+a*{s+1}+ \cdots +a_t）的话，那么 d_i 的左儿子节点表示的是区间

[ s, \frac{s+t}{2} ]，d_i 的右儿子表示的是区间

[ \frac{s+t}{2} +1,t ]。

在实现时，我们考虑递归建树。设当前的根节点为 p，如果根节点管辖的区间长度已经是 1，则可以直接根据 a 数组上相应位置的值初始化该节点。否则我们将该区间从中点处分割为两个子区间，分别进入左右子节点递归建树，最后合并两个子节点的信息。

#### 实现

此处给出代码实现，可参考注释理解：