#include<iostream>
using namespace std;

int head[100000], cnt;
long long ans[1000000];
bool vis[1000000];
int m, n, s;

struct edge
{
    int to;
    int nextt;
    int wei;
} edge[1000000];

// 添加边的函数，x到y的边权重为z
void addedge(int x, int y, int z)
{
    edge[++cnt].to = y;
    edge[cnt].wei = z;
    edge[cnt].nextt = head[x];
    head[x] = cnt;
}

int main()
{
    cin >> m >> n >> s; // 输入总点数m，总边数n，以及起始点s

    for (int i = 1; i <= n; i++)
    {
        ans[i] = 2147483647; // 初始化ans数组为最大值，表示距离为无穷大
    }
    ans[s] = 0; // 起始点到自身的距离为0

    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // 输入边的起点a，终点b，边的权重c
        addedge(a, b, c); // 添加边到邻接表中
    }

    int pos = s; // 当前处理的节点为起始点s

    while (vis[pos] == 0)
    {
        long long minn = 2147483647; // 初始化最小距离为最大值
        vis[pos] = 1; // 标记当前节点已经访问过

        // 遍历以当前节点为起点的所有边
        for (int i = head[pos]; i != 0; i = edge[i].nextt)
        {
            if (!vis[edge[i].to] && ans[edge[i].to] > ans[pos] + edge[i].wei)
            {
                ans[edge[i].to] = ans[pos] + edge[i].wei; // 更新从起始点到该节点的距离
            }
        }

        // 找到下一个未访问的节点，即距离最小的节点
        for (int i = 1; i <= m; i++)
        {
            if (ans[i] < minn && vis[i] == 0)
            {
                minn = ans[i];
                pos = i;
            }
        }
    }

    // 输出起始点到所有点的最短距离
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
}

