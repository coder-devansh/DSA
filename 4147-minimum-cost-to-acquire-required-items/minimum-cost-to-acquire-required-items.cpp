class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini=LLONG_MAX;
        long long c1=(long long)cost1*(long long)need1;
        long long c2=(long long)cost2*(long long)need2;
        mini=min(mini,c1+c2);
        mini=min(mini,(long long)costBoth*(long long)max(need1,need2));
        int min_need=min(need1,need2);
        long long min_cost=(long long)costBoth*(long long)min(need1,need2);
        if(need1-min_need>0){
            min_cost+=(long long)(need1-min_need)*(long long)cost1;
        }
        if(need2-min_need>0){
            min_cost+=(long long)(need2-min_need)*(long long)cost2;
        }
        mini=min(mini,(long long)min_cost);
        return mini;
        
    }
};