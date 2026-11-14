#include <vector>
#include <cassert>
#include <iostream>

class DisjointSets {
public:
    DisjointSets(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    void connect(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

private:
    std::vector<int> parent;
};

int main() {
    DisjointSets ds(6);

    ds.connect(0, 1);
    ds.connect(1, 2);
    ds.connect(3, 4);

    assert(ds.isConnected(0, 2) == true);
    assert(ds.isConnected(3, 4) == true);
    assert(ds.isConnected(0, 3) == false);
    assert(ds.isConnected(0, 5) == false);

    ds.connect(2, 3);
    assert(ds.isConnected(0, 4) == true);
    assert(ds.isConnected(0, 3) == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
