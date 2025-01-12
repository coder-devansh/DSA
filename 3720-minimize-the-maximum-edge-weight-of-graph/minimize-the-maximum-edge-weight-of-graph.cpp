class Solution {
public:
vector<int>vis;

int bfs(unordered_map<int,vector<pair<int,int>>>&adj,int m,vector<int>&vis){
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0]=1;
    int count=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int node=it.first;
        int weight=it.second;
        for(auto it:adj[node]){
            int edw=it.second;
            int n=it.first;
            if(edw<=m && !vis[n]){
                count++;
                vis[it.first]=1;
                q.push({it.first,edw});
            }
        }
      
    }
    cout<<count<<endl;
      return count;

}
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
      unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it:edges){
            adj[it[1]].push_back({it[0],it[2]});
        }
       int high=1e6+1;
       int low=1;
       
       while(low<high){
        int mid=(low+high)/2;
       
      
        if(vector<int>vis(n);bfs(adj,mid,vis)==n){
            high=mid;
        }else{
            low=mid+1;
        }

       }
       return low==1e6+1?-1:low;
    }
};