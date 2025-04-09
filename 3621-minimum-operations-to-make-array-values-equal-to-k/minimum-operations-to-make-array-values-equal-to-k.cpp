class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size()==1){
            if(nums[0]==k) return 0;
            else if(nums[0]<k) return -1;
            return 1;
        }
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int count=0;
        bool found=false;
       
        for(auto it:mp){
            if(it.first>k){
                count++;
            }
            else if(it.first<k) found=true;

        }
        if(found) return -1;
        else if(!found && count==0) return 0; 
        return count;
        
    }
};