class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>nums(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                nums[i]=nums[i-1]+1;
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                nums[i]=max(nums[i],nums[i+1]+1);
            }
        }
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        return sum;
     

        
    }
};