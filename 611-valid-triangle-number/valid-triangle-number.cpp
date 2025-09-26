class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=nums.size()-1;
        int ans=0; 
        int result=0;
        sort(nums.begin(),nums.end());
        int lastindex=0;
     
        for(int i=n-1;i>=2;i--)
        {
            int left=0;
            int right=i-1;
            while(left<right)
            {
                if(nums[left]+nums[right]>nums[i])
                {
                    result+=abs(left-right);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return result;

        
        
        
    }
};