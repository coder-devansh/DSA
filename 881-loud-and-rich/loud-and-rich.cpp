class Solution {
public:
void dfs(int node,vector<int>adj[],vector<int>&quiet,vector<int>&ans){
    if(ans[node]!=-1)
    {
        return;
    }
    ans[node]=node;
    

    for(auto it:adj[node])
    {
        dfs(it,adj,quiet,ans);
        if(quiet[ans[it]]<quiet[ans[node]])
        {
            ans[node]=ans[it];
        }
    }
    
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>adj[n];
        for(auto it:richer){
            adj[it[1]].push_back(it[0]);
        }
     
        vector<int>ans(n,-1);

        for(int i=0;i<quiet.size();i++){
            if(ans[i]==-1)
            {
                 ( dfs(i,adj,quiet,ans));

            }
        }
           
          
        
          
           
        return ans;
        
    }
};