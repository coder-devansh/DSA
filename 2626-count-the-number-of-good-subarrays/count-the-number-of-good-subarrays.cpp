class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int count_pair=0;
        int left=0;
        
        int right=0;
        unordered_map<int,int>freq;
        long long  res=0;
        while(right<nums.size()){
            int val=nums[right];
            count_pair+=freq[val];
            freq[val]++;
            while(count_pair>=k){
                res+=nums.size()-right;
                freq[nums[left]]--;
                count_pair-=freq[nums[left]];
                left++;
            }
            right++;
            
        }
        return res;


        
    }
};