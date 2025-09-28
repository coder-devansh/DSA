class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<bool>inc(n+1,false);
        vector<bool>dec(n+1,false);
        vector<long long>prefix(n+1,0);
        inc[0]=true;
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                inc[i]=false;
            }else{
                inc[i]=inc[i-1];
            }
            prefix[i]=prefix[i-1]+nums[i];
        }
        dec[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                dec[i]=false;

            }
            else{
                dec[i]=dec[i+1];

            }
        }
        long long min_diff=LLONG_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(inc[i] && dec[i+1]){
            long long diff=abs(prefix[i]-(prefix[n-1]-prefix[i]));
            min_diff=min(min_diff,diff);

            }
        }
        if(min_diff==LLONG_MAX)return -1;
        return min_diff;

        
    }
};