class Solution {
public:

void dfs(int node,vector<int>adj[],vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            
            dfs(it,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int>adj[isConnected.size()];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
          
            vector<int>vis(isConnected.size(),0);
            int cnt=0;
            for(int i=0;i<isConnected.size();i++){
                if(!vis[i])
                {
                    cnt++;
                    dfs(i,adj,vis);
                }
            }
           
        
        return cnt;

        
    }
};