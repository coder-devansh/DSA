class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
       vector<int>prefix(nums.size(),0);
       vector<int>suffix(nums.size(),0);
        vector<int>ans(nums.size(),0);
        map<int,int>mp;
        prefix[0]=nums[0];
        mp[nums[0]]=0;
    
        for(int i=1;i<nums.size();i++){
            mp[nums[i]]=i;
            prefix[i]=max(nums[i],prefix[i-1]);
        }
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        ans[nums.size()-1]=prefix[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            ans[i]=prefix[i];
            if(prefix[i]>suffix[i+1]){
                ans[i]=ans[i+1];
            }
        }
        return ans;
        
        
    }
};