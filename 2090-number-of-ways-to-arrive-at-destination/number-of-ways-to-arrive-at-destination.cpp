class Solution {
public:
long long   dfs(int src,vector<vector<pair<int,int>>>&adj,vector<int>&vis,int n){
    int MOD=1e9+7;
  priority_queue<pair<long long , long long >, vector<pair<long long , long long >>, greater<pair<long long , long long>>> pq;
    vector<long long > dist(n + 1, LLONG_MAX);
    vector<int> ways(n + 1, 0);

    pq.push({0, src});
    dist[src] = 0;
    ways[src] = 1;

    while (!pq.empty()) {
        long long  d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int nextNode = it.first;
            long long  edw = it.second;

            if (dist[node] + edw < dist[nextNode]) {
                dist[nextNode] = dist[node] + edw;
                pq.push({dist[nextNode], nextNode});
                ways[nextNode] = ways[node]; // New shortest path found
            } else if (dist[node] + edw == dist[nextNode]) {
                ways[nextNode] = (ways[nextNode] + ways[node]) % MOD; // Multiple shortest paths
            }
        }
    }
    return (long long )ways[n-1];
}
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>vec(n);
         vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            vec[it[0]].push_back({it[1],it[2]});
            vec[it[1]].push_back({it[0],it[2]});
        }
        vector<int>vis(n,0);
        long long  maxi=dfs(0,vec,vis,n);
        if(maxi==0) return 1;
        return maxi;
        
        
        
    }
};