class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>left;
        vector<int>right;
        if(nums.size()==1){
            return ;
        }
        k=k%nums.size();
       for(int i=nums.size()-k;i<nums.size();i++){
        right.push_back(nums[i]);
       }
       for(int i=0;i<nums.size()-k;i++){
        left.push_back(nums[i]);
       }
       nums.clear();
       for(int i=0;i<right.size();i++){
        nums.push_back(right[i]);
       }
       for(int i=0;i<left.size();i++){
        nums.push_back(left[i]);
       }
        

        
    }
};