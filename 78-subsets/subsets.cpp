class Solution {
public:
vector<vector<int>>result;
void find(int i,vector<int>&nums,vector<int>ans){
    if(i==nums.size()){
        result.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    find(i+1,nums,ans);
    ans.pop_back();
    find(i+1,nums,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>ans;
        find(0,nums,ans);
        return result;
        
    }
};