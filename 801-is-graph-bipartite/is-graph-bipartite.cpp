class Solution {
public:
bool dfs(int node,vector<int>adj[],int col,vector<int>&vis){
    vis[node]=col;
    for(auto it:adj[node])
    {
        if(vis[it]==-1){
            if(dfs(it,adj,1-col,vis)==false) return false;
        }
        else{
            if(vis[it]==col){
                return false;
            }
        }
       
    }

     return true;
    
}

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>adj[graph.size()];

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);

            }
        }
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
               if( dfs(i,adj,0,vis)==false) return false;;
            }
        }
        return true;

        
    }
};