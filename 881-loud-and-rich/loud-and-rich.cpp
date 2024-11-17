class Solution {
public:
    // Function to perform DFS
    void dfs(int node, vector<int>& quiet, vector<int>& ans, vector<vector<int>>& adj) {
        // If the answer for the current node is already computed, no need to process it again
        if (ans[node] != -1) return;
        
        // Initially, the answer for this node is the node itself
        ans[node] = node;
        
        // Traverse all the richer people of the current node
        for (int neighbor : adj[node]) {
            // Recursively process the neighbor
            dfs(neighbor, quiet, ans, adj);
            
            // If the neighbor has a quieter person, update the answer for the current node
            if (quiet[ans[neighbor]] < quiet[ans[node]]) {
                ans[node] = ans[neighbor];
            }
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        // Adjacency list to store the graph
        vector<vector<int>> adj(n);
        
        // Building the adjacency list from the richer relations
        for (const vector<int>& edge : richer) {
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Result array to store the answer for each person
        vector<int> ans(n, -1);
        
        // Perform DFS for each person if their answer is not computed
        for (int i = 0; i < n; ++i) {
            if (ans[i] == -1) {
                dfs(i, quiet, ans, adj);
            }
        }
        
        return ans;
    }
};
