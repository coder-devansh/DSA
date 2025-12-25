class Solution {
public:
vector<int>ans;
void dfs(int node,int par,map<int, map<int,int>>&count,string&labels,vector<vector<int>>&adj){
    count[node][labels[node]-'a']++;
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,node,count,labels,adj);
        for(auto&p:count[it]){
            count[node][p.first]+=p.second;
        }
    }
    ans[node]=count[node][labels[node]-'a'];
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        ans.assign(n, 0);
        map<int, map<int,int>> count;
        dfs(0,-1,count,labels,adj);
        return ans;

        
    }
};