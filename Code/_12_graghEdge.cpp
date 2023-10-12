//2023/10/8
#include <iostream>
#include <vector>

using namespace std;

// 定义表示图的边的结构体
struct Edge {
    int u, v; // 边的两个端点
};

int n, m; // n代表顶点数，m代表边数
vector<Edge> e; // 存储图的边的向量
vector<bool> vis; // 用于记录顶点的访问状态的向量

// 查找是否存在边 (u, v) 的函数
bool find_edge(int u, int v) {
    for (int i = 1; i <= m; ++i) { // 遍历所有边
        if (e[i].u == u && e[i].v == v) { // 如果找到匹配的边
            return true; // 返回true，表示存在这条边
        }
    }
    return false; // 遍历完所有边都没有找到匹配的边，返回false，表示不存在这条边
}

// 深度优先搜索函数，用于遍历图
void dfs(int u) {
    if (vis[u]) return; // 如果顶点u已经被访问过，直接返回，避免重复访问
    vis[u] = true; // 标记顶点u为已访问

    for (int i = 1; i <= m; ++i) { // 遍历所有边
        if (e[i].u == u) { // 如果边的起点是顶点u
            dfs(e[i].v); // 递归访问与顶点u相邻的顶点e[i].v
        }
    }
}

int main() {
    cin >> n >> m; // 从标准输入读取顶点数n和边数m

    vis.resize(n + 1, false); // 初始化vis向量，大小为n+1，所有元素初始为false
    e.resize(m + 1); // 初始化e向量，大小为m+1

    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v; // 从标准输入读取边的信息，存储在e向量中
    }

    return 0; // 程序结束
}
