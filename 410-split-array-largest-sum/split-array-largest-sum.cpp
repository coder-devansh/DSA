class Solution {
public:
bool canPossible(int mid,vector<int>nums,int k){
    int sum=0;
    int count=1;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>mid){
            sum=nums[i];
            count++;
            if(count>k){
                return false;
            }
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(auto it:nums)high+=it;
        while(low<high){
            int mid=(low+(high-low)/2);
            if(canPossible(mid,nums,k)){
                high=mid;
            }else{
                low=mid+1;
            }

        }
        return low;
        
    }
};