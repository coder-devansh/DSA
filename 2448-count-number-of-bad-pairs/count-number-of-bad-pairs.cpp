class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>mp;
         long long  count=0;
        for(int i=0;i<nums.size();i++){
            
                     mp[nums[i]-i]++;
                     count+=i-(mp[nums[i]-i]);
            
            
        }
       
        for(auto it:mp){
            count+=it.second;

        }
        if(mp.size()==1){
            return 0;
        }
        return count;
         

        
    }
};