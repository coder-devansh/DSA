#define ll long long
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        ll product=1;
        int count=0;
        while(right<nums.size()){
            product*=nums[right];
            while(left<right && product>=k){
                product/=nums[left];
                left++;
            }
            if(product<k){
            count+=(right-left+1);
            }
            right++;  
        }
        return count;
        
    }
};