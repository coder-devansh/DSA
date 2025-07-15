class Solution {
public:
bool dfs(int i,vector<vector<int>>adj,int parent,vector<int>&vis,vector<int>&color){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
        
            color[it]=1-color[i];
            if(!dfs(it,adj,i,vis,color))return false;
        }else if(color[it]==color[i]){
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        vector<int>color(graph.size()+1,-1);
        vector<int>vis(graph.size()+1,0);
        for(int i=0;i<=graph.size()-1;i++){
            if(!vis[i] && color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,-1,vis,color))return false;
            }

        }
        return true;
        
    }
};