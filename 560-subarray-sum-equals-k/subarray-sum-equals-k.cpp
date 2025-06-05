class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1 && k==0){
            return 0;
        }
        int count=0;
        int sum=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
           
            count+=mp[sum-k];
             mp[sum]++;
            

        }
        return count;

        
    }
};