class Solution {
public:
vector<vector<int>>dp1;
vector<vector<vector<int>>>dp2;
int no_inc(int i,int n,vector<int>&nums,int prev,int inc,int cost){
    if(cost==inc){
        return 1;
    }
    if(i==n){
        return 0;
    }
    if(dp2[i][prev+1][cost]!=-1)return dp2[i][prev+1][cost];
    
    long long left=0;
    if(prev==-1 || nums[i]>nums[prev]){
        left=no_inc(i+1,n,nums,i,inc,cost+1);
    }
   long long right=no_inc(i+1,n,nums,prev,inc,cost);
   return dp2[i][prev+1][cost]=left+right;
}
int lis(int i,int n,vector<int>&nums,int prev){
    if(i==n){
        return 0;
    }
    if(dp1[i][prev+1]!=-1)return dp1[i][prev+1];
    long long left=0;
    if(prev==-1 || nums[prev]<nums[i]){
        left=1+lis(i+1,n,nums,i);
    }
    long long right=lis(i+1,n,nums,prev);
    return dp1[i][prev+1]=max(left,right);
}
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>forward(nums.size(),1);
        vector<int>count(nums.size()+1,1);
        count[1]=1;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+forward[j]>forward[i]){
                   
                    forward[i]=1+forward[j];
                    count[i]=count[j];
                }else if(nums[i]>nums[j] && forward[i]==1+forward[j]){
                    count[i]+=count[j];
                }
                
            }
            maxi=max(maxi,forward[i]);
        }
        if(maxi==1){
            return nums.size();
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(forward[i]==maxi)ans+=count[i];
        }

        return ans;
        
        
    }
};