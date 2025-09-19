class Solution {
public:
int countPair(int mid,vector<int>nums){
    int j=0;
    int count_pair=0;
    for(int i=0;i<nums.size();i++){
        while(j<nums.size() && nums[j]-nums[i]<=mid){
            j++;
        }
        count_pair+=j-i-1;
    }
    return count_pair;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1]-nums[0];
        while(low<high){
            int mid=(low+high)/2;
            if(countPair(mid,nums)>=k)
            {
                high=mid;
            }else{
                low=mid+1;
            }
        }
        
        return low;
    }
};