class Solution {
public:
int edge;
int vertices;

void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
    vis[i]=1;
    vertices++;

    for(auto it:adj[i])
    {
        
            edge++;
        

        if(!vis[it])
        {
            dfs(it,adj,vis);
        }

    }
   
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int count=0;

        for(int i=0;i<=n-1;i++){
            if(!vis[i])
            {
                edge=0;
                vertices=0;
                
                dfs(i,adj,vis);
                edge/=2;
               int value=(vertices*(vertices-1))/2;
               if(value==edge) count+=1;
            }

        }
        return count;
    }
};