#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005; // 最大顶点数和边数

int n, m, cnt;
struct Edge
{
    int to, w, next;
}edge[MAXN];
int head[MAXN];
void init() {
    for (int i = 1;i <= n;i++)
        head[i] = -1;
    cnt = 0;//边计数器，用于表示当前边的数量
}
void add(int u, int v, int w) {
    edge[cnt].to = v;// 存储边的终点
    edge[cnt].w = w; // 存储边的权重
    edge[cnt].next = head[u];// 将当前边连接到顶点u的链表中
    head[u] = cnt++;// 更新头节点数组，指向新添加的边
}


int main() {
    cin >> n >> m;
    int u, v, w;
    init();
    for (int i = 1;i <= m;i++) {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i = 1;i <= n;i++) {
        cout << i << endl;
        for (int j = head[i];j != -1;j = edge[j].next)
            cout << i << " " << edge[j].to << " " << edge[j].w << endl;
        cout << endl;
    }
    return 0;
}