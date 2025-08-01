class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long > dist(n + 1, LLONG_MAX);
        vector<int>ways(n,0);
        q.push({0,0});
        ways[0]=1;
        dist[0]=0;
        int mod=(int)(1e9+7);
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            long long  distance=it.first;
            int node=it.second;
            if (distance > dist[node]) continue;
            for(auto it:adj[node]){
                int road_node=it.first;
                long long  road_distance=it.second;
                if(dist[node]+road_distance<dist[road_node]){
                    dist[road_node]=dist[node]+road_distance;
                    ways[road_node]=ways[node];
                    q.push({dist[road_node],road_node});
                }else if(dist[node]+road_distance==dist[road_node]){
                    ways[road_node]=(ways[road_node]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];

        
    }
};