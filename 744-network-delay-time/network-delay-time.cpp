class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        queue<int>q;
        q.push(k);
        dist[k]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it;
            for(auto it:adj[node]){
                int network_node=it.first;
                int edge_w=it.second;
                if(dist[node]+edge_w<dist[network_node]){
                    dist[network_node]=dist[node]+edge_w;
                    q.push(network_node);
                }
            }
        }
        int minValue=0;
        for(auto it:dist)cout<<it<<" ";
        for(int i=1;i<=n;i++){
            minValue=max(dist[i],minValue);
            if(dist[i]==1e9)return -1;
        }
        return minValue;



        
    }
};