class Solution {
public:
int  dfs(int node,vector<vector<int>>&adj,int parent,int depth,vector<int>&color){
    int count=depth%2==0?1:0;
    color[node]=depth%2;
    for(auto it:adj[node]){
        if(it!=parent){
            count+=dfs(it,adj,node,depth+1,color);
        }
    }
    return count;
    
}
int  odd_dfs(int node,vector<vector<int>>&adj,int parent,int depth,vector<int>&color)
{
     int count=depth%2!=0?1:0;
     color[node]=depth%2;
    for(auto it:adj[node]){
        if(it!=parent){
            count+=odd_dfs(it,adj,node,depth+1,color);
        }
    }
    
     
    return count;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        vector<vector<int>>adj(n+1);
        vector<vector<int>>adj1(m+1);
        for(auto it:edges1){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        vector<int>vis1(m+1,0);
        // int h1=findHeight(0,adj,vis);
        // cout<<h1;
        vector<int>ans;
        
        vector<int>color1(n+1,0);
        int res=dfs(0,adj,-1,0,color1);
        ans.push_back(res);
        for(int i=1;i<=n;i++){
            if(color1[i]){
                ans.push_back(n+1-res);
            }else{
                 ans.push_back(res);

            }
           
           
           
        }
        int maxi=1;
        vector<int>color(m+1,0);
        int val=odd_dfs(0,adj1,-1,0,color);
        maxi=max(val,m+1-val);
        for(int i=0;i<ans.size();i++){
            ans[i]+=maxi;
        }
        return ans;
        
    }
};