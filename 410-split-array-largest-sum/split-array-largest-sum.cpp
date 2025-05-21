class Solution {
public:
bool find(vector<int>&nums,int mid,int k){
    int total=0;
    int split=1;
    for(int i=0;i<nums.size();i++){
        total+=nums[i];
        if(total>mid){
            split++;
            total=nums[i];
            if(split>k){
                return false;
            }
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int ans=0;
        int right=0;
        for(auto it:nums){
            right+=it;
        }
        while(left<right){
            int mid=left+(right-left)/2;
          if(find(nums,mid,k)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
        
    }
};