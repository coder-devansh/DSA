class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long >suffix(nums.size(),-1);
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],(long long)nums[i]);
            
        }
        vector<long long>prefix(nums.size(),-1);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=max((long long )nums[i],prefix[i-1]);

        }
        long long maxi=INT_MIN;
        for(int  i=1;i<nums.size()-1;i++){
            if((prefix[i-1]-nums[i])<0){
                continue;
            }
            long long val=(prefix[i-1]-nums[i])*suffix[i+1];
            maxi=max(val,maxi);
        }
        if(maxi<0) return 0;
        return maxi;
        
    }
};