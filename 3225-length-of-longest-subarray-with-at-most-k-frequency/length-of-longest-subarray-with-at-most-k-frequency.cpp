class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);

        }
        int n=nums.size();
        int left=0;
        int right=0;
        int maxi=0;
        map<int,int>mp;
        
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;

            }
           
                maxi=max(maxi,right-left+1);
            
            right++;

        }
        
        return maxi;
    }
};