class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor1=0;
        int count1=0;
        for(auto it:nums){
            if(it==0)count1++;
            xor1^=it;
        }
        if(xor1!=0)return nums.size();
        if(count1==nums.size())return 0;
        return nums.size()-1;

        
    }
};