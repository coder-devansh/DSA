class Solution {
public:
set<int>st;
void dfs(int node,vector<int>adj[],set<int>&st){
    if(st.find(node)==st.end()){
           st.insert(node);
    }
   
    for(auto it:adj[node])
    {
        dfs(it,adj,st);
    }
}
    int findChampion(int n, vector<vector<int>>& edges) {
       vector<int>adj(n,0);
        for(auto it:edges){
            adj[it[1]]++;
            
        }
        vector<int>result;
       for(int i=0;i<n;i++){
        if(adj[i]==0){
            result.push_back(i);
        }
       }
       if(result.size()==1){
        return result[0];
       }
        
       if(result.size()>1){
        return -1;
       }
       return -1;

        
    }
};