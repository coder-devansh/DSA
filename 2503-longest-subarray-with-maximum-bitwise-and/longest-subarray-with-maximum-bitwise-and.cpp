class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size=0;
        int max_value=*max_element(nums.begin(),nums.end());
        
        int max_size=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max_value){

                while(i<nums.size() && nums[i]==max_value){
                    size++;
                    i++;
                }
                max_size=max(size,max_size);
                size=0;

            }
        }
        return max_size;

        
    }
};