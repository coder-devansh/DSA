class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>prefix(nums.size()+1,0);
        for(auto it:queries){
            prefix[it[0]]-=1;
            prefix[it[1]+1]+=1;
        }
        for(int i=0;i<nums.size();i++){
             if(i>0){
                prefix[i]+=prefix[i-1];
            }
            if(nums[i]==0){
                continue;
            }
            nums[i]=nums[i]+prefix[i];
           
        }
        for(auto it:nums){
            if(it>0){
                return false;
            }
        }
    
        return true;
    }
};