// (-target to target)
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(-target <= (nums[j] - nums[i])  && (nums[j] - nums[i])<= target){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>best(n+1,0);
        set<int>st;
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        best[0]=0;
        int maxi=INT_MIN;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int jump=it.first;
            
            if(node==n-1){
               maxi=max(maxi,jump);
               continue;
            }
            if(best[node]>jump)continue;
            for(auto ele:adj[node]){
                
                if(best[ele]<(jump+1)){
                best[ele]=jump+1;
                pq.push({jump+1,ele});
                }

            }

        }
        if(maxi==INT_MIN)return -1;
        return maxi;
        
        
                
    }
};