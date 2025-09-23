class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p2=cost[0];
        int p1=cost[1];
        for(int i=2;i<cost.size();i++){
            int curr=cost[i]+min(p1,p2);
            p2=p1;
            p1=curr;
        }
        return min(p1,p2);

        
    }
};