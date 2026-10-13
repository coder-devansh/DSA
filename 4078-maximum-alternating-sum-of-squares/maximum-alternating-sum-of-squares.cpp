class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        long long ans=0;
        while(i<j){
            ans+=(nums[j]*nums[j])-(nums[i]*nums[i]);
            i++;
            j--;
        }
        if(nums.size()%2!=0)ans+=(nums[i]*nums[i]);
        return ans;


    }
};