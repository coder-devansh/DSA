class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>mp;
         long long  count=0;
        for(int i=0;i<nums.size();i++){
                       count+=i-(mp[nums[i]-i]);
                     mp[nums[i]-i]++;
                    
            
            
        }
       
        
        if(mp.size()==1){
            return 0;
        }
        return count;
         

        
    }
};