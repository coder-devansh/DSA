class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        k=nums.size()-k;
        int right=0;
        int left=0;
        int sum=0;
        int max_score=0;
        int total_points=accumulate(nums.begin(),nums.end(),0);
        while(right<nums.size()){
            sum+=nums[right];
            while(left<right && (right-left+1)>k){
                sum-=nums[left];
                left++;
            }
            if((right-left+1)==k){
                max_score=max(max_score,total_points-sum);
            }
            right++;

        }
        return max_score==0?total_points:max_score;

        
    }
};