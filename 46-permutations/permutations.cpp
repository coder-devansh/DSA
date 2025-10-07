class Solution {
public:
vector<vector<int>>result;
void permute(int i,vector<int>nums){
    if(i==nums.size()){
        result.push_back(nums);
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        permute(i+1,nums);
        swap(nums[j],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        permute(0,nums);
        return result;
        
    }
};