class Solution {
public:

vector<int>lis={0};


vector<vector<int>>result;
void dfs(int node,vector<int>adj[],int n){
    if(node==n){
        result.push_back(lis);
        return ;
    }


    for(auto it:adj[node])
    {
        lis.push_back(it);
        dfs(it,adj,n);
        lis.pop_back();
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>adj[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                 adj[i].push_back(graph[i][j]);

            }
           
        }
        
        dfs(0,adj,graph.size()-1);
        return result;
        
        
    }
};