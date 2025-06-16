class Solution {
public:
vector<vector<int>>result;
void find(int i,vector<int>&nums,int target,vector<int>temp){
    if(target==0){
        result.push_back(temp);
        return;
    }
    if(target<0){
        return;
    }
    if(i>=nums.size())return;
    if(target>=nums[i]){
        temp.push_back(nums[i]);
        find(i,nums,target-nums[i],temp);
        temp.pop_back();
    }
    find(i+1,nums,target,temp);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        find(0,candidates,target,temp);
        return result;
        
    }
};