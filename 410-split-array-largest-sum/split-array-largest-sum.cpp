class Solution {
public:
bool canbepossible(vector<int>&nums,int mid,int k){
    int count=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>mid){
            count++;
            sum=nums[i];
            if(count>k)return false;
        }
    }
    return true;
}

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(auto it:nums){
            high+=it;
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canbepossible(nums,mid,k)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};