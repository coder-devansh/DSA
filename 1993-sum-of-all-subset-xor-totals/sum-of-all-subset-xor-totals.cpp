class Solution {
public:
int count1=0;
void find_subset(int i,vector<int>&nums,vector<int>&ans){
    if(i==nums.size()){
        int x=0;
        if(ans.size()>0){
            for(auto it:ans){
                x^=it;


            }
            count1+=x;
        }
        return;
    }
    ans.push_back(nums[i]);
    find_subset(i+1,nums,ans);
    ans.pop_back();
    find_subset(i+1,nums,ans);
}
    int subsetXORSum(vector<int>& nums) {
        vector<int>ans;
        find_subset(0,nums,ans);
        return count1;


        
        
    }
};