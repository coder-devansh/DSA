class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        map<int,int>mp;
        bool zero=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero=true;

        }
        if(zero==false){
            return nums.size()-1;
        }
        int maxi=0;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp.size()==2 && mp[0]>1){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);

                }
                left++;
            }
            if(mp.size()==2 && mp[0]<=1){
                maxi=max(maxi,mp[1]);
            }
            right++;

        }
        return maxi;
        
    }
};