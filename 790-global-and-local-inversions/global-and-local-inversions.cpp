class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int local_inversion=0;
        for(int i=0;i<nums.size();i++){
            if(abs(i-nums[i])>1){
                    return false;
            }
        }
        return true;
    }
};