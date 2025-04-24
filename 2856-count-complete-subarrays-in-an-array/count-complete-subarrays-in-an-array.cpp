class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        for(auto it:nums) st.insert(it);
        int size=st.size();
        int left=0;
        int right=0;
        int cnt=0;
        map<int,int>mp;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(left<=right && mp.size()==size){
                cnt+=(nums.size()-right);
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            right++;

        }
        return cnt;
    }
};