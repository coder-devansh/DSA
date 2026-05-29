class Solution {
public:
    int minElement(vector<int>& nums) {
        int minimum=INT_MAX;
        for(auto it:nums){
            int sum=0;
            while(it>0){
                sum+=(it%10);
                it=it/10;
            }
            minimum=min(minimum,sum);
        }
        return minimum;
        
    }
};