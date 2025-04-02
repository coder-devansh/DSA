class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long  maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    maxi=max((long long )((long long )nums[i]-nums[j])*nums[k],maxi);
                }
            }
        }
        if(maxi<0) return 0;
        return maxi;

        
    }
};