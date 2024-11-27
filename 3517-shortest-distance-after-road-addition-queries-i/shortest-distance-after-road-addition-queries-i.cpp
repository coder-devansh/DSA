class Solution {
public:
    // Function to perform BFS and calculate the shortest distance from node 0 to node n-1
    int bfs(vector<int> adj[], int n) {
        vector<int> dis(n, 1e9);  // Distance array, initialized to a large value
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                // If a shorter path to 'neighbor' is found
                if (dis[node] + 1 < dis[neighbor]) {
                    dis[neighbor] = dis[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        return dis[n - 1];  // Return the distance to node n-1
    }

    // Function to handle the queries and return the shortest distances after each query
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        
        // Create the initial graph (consecutive nodes are connected)
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
          
        }

        vector<int> result;
        
        // Process each query
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            
            // Add the edge for the current query
            adj[u].push_back(v);
            
            // Perform BFS to find the shortest path from node 0 to node n-1
            result.push_back(bfs(adj, n));
        }
        
        return result;
    }
};
