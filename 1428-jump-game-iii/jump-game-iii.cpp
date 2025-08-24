class Solution {
public:

    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<nums.size();i++){
            if(i+nums[i]<nums.size()){
                adj[i].push_back(i+nums[i]);
            }
            if(i-nums[i]>=0){
                adj[i].push_back(i-nums[i]);
            }
        }
        queue<int>q;
        q.push(start);
        vector<int>vis(nums.size(),0);
        vis[start]=1;
        if(nums[start]==0)return true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    if(nums[it]==0)return true;
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;

        
    }
};