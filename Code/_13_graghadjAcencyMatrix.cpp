//2023/10/8
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<bool>vis;
vector<vector<bool>>adj;//邻接矩阵，用来表示图的连接关系

//判断是否存在边(u,v)
bool find_edge(int u, int v) {
    return adj[u][v];
}

//深度优先搜索遍历图
void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = true;
    for (int v = 1;v <= n;v++) {
        if (adj[u][v])
            dfs(v);
    }
}
int main() {
    cin >> n >> m; // 从标准输入读取顶点数n和边数m

    vis.resize(n + 1, false); // 初始化vis向量，大小为n+1，所有元素初始为false
    adj.resize(n + 1, vector<bool>(n + 1, false)); // 初始化邻接矩阵adj，大小为(n+1) x (n+1)，所有元素初始为false

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true; // 标记有边(u, v)
    }

    return 0; // 程序结束
}
