#include<iostream>
#include<vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    /* rank 的作用是记录树的高度或秩。在执行合并操作时，通过比较两个根节点（集合的代表元素）的 rank，可以决定将哪个树合并到另一个树上。通常，我们希望将较小秩的树合并到较大秩的树上，以避免树的高度过大，从而保持并查集操作的高效性。 */
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y)
            return false;
        if (rank[root_x] > rank[root_y])
            parent[root_y] = root_x;
        else if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int k;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> k;
        if (k == 1) {
            cin >> x >> y;
            uf.unite(x, y);
        }
        else {
            cin >> x >> y;
            if (uf.find(x) == uf.find(y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}