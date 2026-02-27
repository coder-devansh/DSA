class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};

class Solution {
public:

    bool canBuild(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);
        int used = 0;
        int upgrades = 0;

        // 1️⃣ Include must edges
        for (auto &e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid) return false;
                if (!dsu.unite(e[0], e[1])) return false;
                used++;
            }
        }

        // 2️⃣ First use strong optional edges
        for (auto &e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                if (dsu.unite(e[0], e[1])) {
                    used++;
                }
            }
        }

        // 3️⃣ Then try upgradeable edges
        for (auto &e : edges) {
            if (e[3] == 0 && e[2] < mid && 2 * e[2] >= mid) {
                if (dsu.unite(e[0], e[1])) {
                    upgrades++;
                    used++;
                }
            }
        }

        if (used != n - 1) return false;
        return upgrades <= k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int low = 0, high = 0;

        for (auto &e : edges)
            high = max(high, 2 * e[2]);

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canBuild(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};