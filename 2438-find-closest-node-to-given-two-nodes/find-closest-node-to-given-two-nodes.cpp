class Solution {
public:
vector<int>bfs(int node,vector<vector<int>>&adj){
    int n=adj.size();
    queue<pair<int,int>>q;
    vector<int>vis(n,0);
    vector<int>dist(n+1,INT_MAX);
    q.push({node,0});
    dist[node]=0;
    vis[node]=1;
    while(!q.empty()){
        auto it=q.front();
        int u=it.first;
        q.pop();
        int distance=it.second;
        for(auto it:adj[u]){
            if(!vis[it]){
                if(dist[u]+1<dist[it]){
                    dist[it]=dist[u]+1;
                    vis[it]=1;
                    q.push({it,dist[it]});
                }
            }
        }
    }
    return dist;
}

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
           edges[i] != -1 ? adj[i].push_back(edges[i]) : void();
        }
        vector<int>dist1=bfs(node1,adj);
        vector<int>dist=bfs(node2,adj);
        int mini=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(dist[i]!=INT_MAX && dist1[i]!=INT_MAX){
                int maxi=max(dist[i],dist1[i]);
                if(mini>maxi){
                    ans=i;
                    mini=maxi;
                }
            }

        }
        return ans;

        
    }
};