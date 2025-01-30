#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj, int node, vector<int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;  // Start with color 0

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto neighbor : adj[curr]) {
                if (color[neighbor] == -1) {  
                    color[neighbor] = 1 - color[curr]; // Assign opposite color
                    q.push(neighbor);
                } else if (color[neighbor] == color[curr]) {  
                    return false; // Conflict found → Not bipartite
                }
            }
        }
        return true;
    }

    int getpath(vector<vector<int>>& adj, int src, int n) {
        queue<int> q;
        vector<int> vis(n + 1, 0);
        q.push(src);
        vis[src] = 1;
        int distance = 0;  // Start from -1 because BFS will increase it after the first level

        while (!q.empty()) {
            int size = q.size();
            distance++; // Increase depth at each level
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (auto neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
        return distance;
    }

    int findMaxGroup(vector<vector<int>>& adj, int node, vector<int>& distance, vector<int>& vis) {
        stack<int> st;
        st.push(node);
        vis[node] = 1;
        int max_groups = distance[node];

        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            for (auto neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    st.push(neighbor);
                    max_groups = max(max_groups, distance[neighbor]);
                }
            }
        }
        return max_groups;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!isBipartite(adj, i, color)) return -1;
            }
        }

        vector<int> distance(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            distance[i] = getpath(adj, i, n);
        }

        vector<int> vis(n + 1, 0);
        int max_groups = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                max_groups += findMaxGroup(adj, i, distance, vis);
            }
        }

        return max_groups;
    }
};
