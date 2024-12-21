class Solution {
public:
vector<long long>dp;
int dfs(int node,int parent,vector<int>adj[],vector<int>&values,int k,int&count){
  if(dp[node]!=-1){
    return dp[node];
  }
long long   sum=0;
    for(auto it:adj[node])
    {
        if(it!=parent){
             
            sum+=dfs(it,node,adj,values,k,count);
            sum=sum%k;
           

        }
    }
    sum+=values[node];
    sum=sum%k;
    if(sum==0){
        count++;
    }
    return dp[node]=sum;



}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n==0){
            return 0;
        }
        vector<int>vis(n,0);
        
       vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
      
      int count=0;
      dp.resize(n,-1);
   
           dfs(0,-1,adj,values,k,count);
           return count;

        

    }
};