class Solution {
public:
   void  isBiparit(vector<vector<int>>&adj,int node,vector<int>&color,vector<int>&vis,int clr)
{   vis[node]=1;
    color[node]=clr;
    for(auto it:adj[node]){
        if(!vis[it]){
           
            isBiparit(adj,it,color,vis,1-clr);
        }
    }
    
}
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size()+1);
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);


            }
        }
        vector<int>color(graph.size()+1,-1);
        vector<int>vis(graph.size()+1,0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
               isBiparit(adj,i,color,vis,0);
            }
        }
         for(int i=0;i<graph.size();i++){
            for(auto it:adj[i])
            {
                if(color[it]==color[i])
                {
                    return false;
                }
            }
         }
         return true;
        
    }
};