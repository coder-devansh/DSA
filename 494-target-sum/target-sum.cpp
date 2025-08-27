class Solution {
public:
int no_of_ways(int i,int sum,vector<int>&nums,int target,map<pair<int,int>,int>&mp){
    if(i==nums.size()){
        return sum==target;
    }
    if(mp.find({i,sum})!=mp.end())return mp[{i,sum}];
    int left=no_of_ways(i+1,sum+nums[i],nums,target,mp);
    int right=no_of_ways(i+1,sum-nums[i],nums,target,mp);
    return mp[{i,sum}]=left+right;
    

}
    int findTargetSumWays(vector<int>& nums, int target) {
     map<pair<int,int>,int>mp;
        return no_of_ways(0,0,nums,target,mp);
        
    }
};