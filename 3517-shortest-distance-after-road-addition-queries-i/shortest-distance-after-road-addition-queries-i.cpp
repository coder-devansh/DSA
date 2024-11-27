class Solution {
public:
int  bfs(vector<int>adj[],int n){
    vector<int>dis(n,1e9);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(!q.empty()){
        auto it=q.front();
        int node=it;
        q.pop();
        for(auto it:adj[node])
        {
            if(dis[node]+1<dis[it])
            {
                dis[it]=dis[node]+1;
                q.push(it);
                
            }
        }

    }
    return dis[n-1];
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
            
        }
        vector<int>result;
        for(auto it:queries){
            adj[it[0]].push_back(it[1]);
           
            result.push_back(bfs(adj,n));
        }
        return result;

        
    }
};