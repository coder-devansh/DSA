class Solution {
public:
long long find(int n){
    long long value=0;
    while(n){
        value+=(n%10);
        n=n/10;

    }
    return value;
}
    int maximumSum(vector<int>& nums) {
        map<long long ,long long >mp;
        long long maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            long long value=find(nums[i]);
            if(mp.find(value)!=mp.end()){
            maxi=max(maxi,nums[i]+mp[value]);
            if(mp[value]<nums[i])
            {
                mp[value]=nums[i];
            }
            }
            else{
                mp[value]=nums[i];
            }
            
            
        }
        if(maxi==INT_MIN){
            return -1;
        }
        return maxi;
        
    }
};