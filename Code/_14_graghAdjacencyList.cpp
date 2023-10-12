#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int>vis;
vector <vector<int>>adj;//邻接表，表示图的连接关系

bool find_edge(int u, int v) {
    for (int i = 0;i <= adj[u].size();i++) {
        if (adj[u][i] == v)
            return true;
    }
    return false;
}

void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = true;
    for (int i = 0;i < adj[i].size();i++) {
        int v = adj[u][i];
        dfs(v);
    }
}
int main() {
    cin >> n >> m;
    vis.resize(n + 1, false);
    adj.resize(n + 1);

    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}