class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)continue;
            nums[i]=-1;
        }
        map<int,int>mp;
        int sum=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0)maxi=max(maxi,i+1);
            else if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }else{
                maxi=max(maxi,i-mp[sum]);
            }
        }
        return maxi;




        
    }
};