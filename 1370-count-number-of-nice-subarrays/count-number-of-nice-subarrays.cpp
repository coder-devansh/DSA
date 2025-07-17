class Solution {
public:
int find(vector<int>nums,int k){
    int right=0;
    int left=0;
    int count=0;
    int ans=0;
    while(right<nums.size()){
        if(nums[right]%2==1){
            count++;
        }
        while(count>k){
            if(nums[left]%2!=0){
                count--;
            }
            left++;
        }
        ans+=right-left+1;
        right++;
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
        
    }
};