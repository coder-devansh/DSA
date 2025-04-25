class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int>count(nums.size()+1,0);
        count[0]=0;
        for(int i=1;i<=nums.size();i++){
            count[i]=count[i-1]+(nums[i-1]%modulo==k?1:0);
        }
        map<int,int>mp;
        long long total_sum=0;
        for(int i=0;i<=nums.size();i++){
            total_sum+=mp[(count[i]+modulo-k)%modulo];
            mp[count[i]%modulo]++;
        }
        return total_sum;
      

        

    }
};