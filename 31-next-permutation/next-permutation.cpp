class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool found=false;
        int ind=-1;
            for( int i=nums.size()-2;i>=0;i--){
                if( nums[i+1]>nums[i]){
                    ind=i;
                    break;
                }
            }
            if(ind==-1){
                reverse(nums.begin(),nums.end());
                return;
            }
            for(int j=nums.size()-1;j>=ind;j--){
                if(nums[ind]<nums[j]){
                    swap(nums[j],nums[ind]);
                    break;
                }

            }
            reverse(nums.begin()+ind+1,nums.end());

        
    }
};