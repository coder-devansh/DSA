class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total_cost=0;
        map<char,long long>mp;
        for(int i=0;i<cost.size();i++){
            total_cost+=cost[i];
            mp[s[i]]+=cost[i];
            
        }
        long long mini=LLONG_MAX;
        for(auto it:mp){
            mini=min(mini,total_cost-it.second);
        }
        return mini;
        
    }
};