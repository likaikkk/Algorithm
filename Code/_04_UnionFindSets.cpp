#include<iostream>
#include<vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int>rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0;i < n;i++) {
            parent[i] = i;//Initially, each node is its own root node
        }
    }

    //Find the representative element(root node) of the set where element x is located
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);//Use path compression optimization
        }
        return parent[x];
    }

    //The merge operation is to merge the set where element x is located and the set where element y is located into one set
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
};

int main() {
    int n = 10;
    UnionFind uf(n);

    uf.unite(0, 1);
    uf.unite(2, 3);
    uf.unite(4, 5);

    cout << uf.find(1) << endl;
    if (uf.find(1) == uf.find(3))
        cout << "1 and 3 are in the same set." << endl;
    else
        cout << "1 and 3 are not in the same set." << endl;

    return 0;
}