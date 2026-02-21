class Solution {
public:
bool canbe(int x,int y,int xl,int xr,int yu,int yd){
if(xl<=x && xr>=x && yu<=y && yd>=y)return true;
return false;
}
int count;
vector<int>vis;
void dfs(int node,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            count++;
            dfs(it,adj);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>>adj(bombs.size()+1);
        for(int i=0;i<bombs.size();i++){
            
            for(int j=0;j<bombs.size();j++){
        long long dx = bombs[i][0] - bombs[j][0];
        long long dy = bombs[i][1] - bombs[j][1];
        long long r = bombs[i][2];

        if(dx*dx + dy*dy <= r*r){
            adj[i].push_back(j);
        }
            }

        }
        int n=bombs.size();
        int max_count=0;
        for(int i=0;i<n;i++){
            vis.assign(n+1,0);
            count=1;
            dfs(i,adj);
            max_count=max(max_count,count);

        }
        return max_count;
     
        
    }
};