class Solution {
public:
void dfs(int node,vector<int>&vis,int comp,vector<multiset<int>>&arr,vector<vector<int>>&adj,vector<int>&nums){
    vis[node]=comp;
    arr[comp].insert(nums[node]);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,comp,arr,adj,nums);
        }
    }
}
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n=nums.size();
        vector<vector<int>>adj(n+1);
        for(auto it:swaps){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<multiset<int>>arr(n+1);
        vector<int>vis(n+1,0);
        int comp=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,comp,arr,adj,nums);
            }
            comp++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                int component=vis[i];
                ans+=0LL+*(--arr[component].end());
                arr[component].erase(--arr[component].end());

            }
            if(i%2!=0){
                int component=vis[i];
                ans-=*(arr[component].begin());
                arr[component].erase(arr[component].begin());
            }
        }
        return ans;
        
    }
};