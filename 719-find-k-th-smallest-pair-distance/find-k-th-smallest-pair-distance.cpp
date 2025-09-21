class Solution {
public:
int countKth(int mid,vector<int>&nums){
    int j=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        while(j<nums.size() &&  nums[j]-nums[i]<=mid){
            j++;
        }
        count+=j-i-1;
    }
    return count;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1]-nums[0];
        while(low<high){
            int mid=(low+high)/2;
            if(countKth(mid,nums)>=k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};