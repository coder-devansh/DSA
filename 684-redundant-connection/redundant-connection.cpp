class Solution {
public:
bool isConnected(int src,int target,vector<vector<int>>&adj,vector<int>&vis){
    vis[src]=1;
    if(src==target){
        return true;
    }
    bool isFound=false;
    for(auto it:adj[src])
    {
        if(!vis[it]){
            isFound=isFound || isConnected(it,target,adj,vis);

        }
    }
    return isFound;

}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto &edge:edges){
            vector<int>vis(n+1,0);
            if(isConnected(edge[0],edge[1],adj,vis))
            {
                return edge;
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return {};
        
        
    }
};