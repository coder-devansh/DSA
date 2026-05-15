class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool found=false;
        int zero=0;
        long long sum=0;
        map<int,int>mp;
        for(auto it:nums){
            if(it==1)found=true;
            if(it==0)zero++;
            mp[it]++;
        }
        map<int,int>mp1;
        if(found==true){
            return (nums.size()-zero);
        }
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            for(int j=2;nums[i]*j<=(int)1e5;j++){
                if(mp.find(nums[i]*j)!=mp.end()){
                    if(mp1.find(nums[i]*j)!=mp1.end())continue;
                    mp1[nums[i]*j]=val;
                }
            }
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
            if(mp1.find(nums[i])!=mp1.end()){
                sum+=mp1[nums[i]];
            }else{
                sum+=nums[i];
            }
        }

        return sum;
        

        
    }
};
