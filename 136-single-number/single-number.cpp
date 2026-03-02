// use bit manipulation for finding the correct ans;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bit(32,0);
        for(int i=31;i>=0;i--){
            for(int j=0;j<nums.size();j++){
                if(((nums[j]>>i) & 1)==1){
                    bit[i]++; // here we have use the bit manipulation to 
                }
            }
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            if(bit[i]%2!=0){
                ans=ans | (1<<i);
            }
        }
        return ans;
        
        
    }
};