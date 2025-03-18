class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int j=0;
        int i=0;
        int maxi=INT_MIN;
        while(j<nums.size()){
            int k=i;
            for(;k<j;k++){
                if((nums[j] & nums[k])!=0)
                {
                    i=k+1;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;

        
        
    }
};