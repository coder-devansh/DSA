class Solution {
public:
vector<unsigned int >dp;
// int find(int i,vector<int>nums,int target){
//     if(target==0){
//         return 1;

//     }
//     if(target<0) return 0;
//     if(dp[target]!=-1){
//         return dp[target];
//     }
//     int ways=0;
//     for(int  num:nums){
//         ways+=find(i,nums,target-num);
//     }
//     return dp[target]=ways;
// }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,0);
        // return find(0,nums,target);
        dp[0]=1;
        for(int t=1;t<=target;t++){
            for(int num:nums){
                if(t>=num){
                    dp[t]+=dp[t-num];

                }
            }
        }
        return dp[target];

        
    }
};