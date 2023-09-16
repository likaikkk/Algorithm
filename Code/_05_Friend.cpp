#include<iostream>
#include<vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
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