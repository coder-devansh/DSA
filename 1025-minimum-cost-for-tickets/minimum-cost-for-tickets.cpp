class Solution {
public:
vector<int>dp;
int solve(int curr,vector<int>&days,vector<int>&costs){
    if(curr>=days.size()){
        return 0;
    }
     if(dp[curr]!=-1)
     {
        return dp[curr];
     }
    int cost1=solve(curr+1,days,costs)+costs[0];
    int nextind=curr;
    while(nextind<days.size() && days[curr]+7>days[nextind])
    {
        nextind++;
    }
    int cost2=solve(nextind,days,costs)+costs[1];
    nextind=curr;
    while(nextind<days.size() && days[curr]+30>days[nextind])
    {
        nextind++;
    }
    int cost3=solve(nextind,days,costs)+costs[2];
    return dp[curr]=min({cost1,cost2,cost3});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size()+1,-1);
        return solve(0,days,costs);
        
    }
};