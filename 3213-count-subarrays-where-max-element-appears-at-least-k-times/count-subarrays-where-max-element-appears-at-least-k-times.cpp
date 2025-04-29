class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxi=*max_element(nums.begin(),nums.end());
        long long res=0;
        int max_element=0;
        while(r<nums.size()){
            if(nums[r]==maxi){
                max_element++;
            }
             
            while(max_element==k){
                
                if(nums[l]==maxi){
                    max_element--;
                }

                
               
                   l++;
                }
                
                res+=l;
                
        
            r++;
        }
            
        
        return res;

        
    }
};