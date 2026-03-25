class Solution {
public:
vector<vector<vector<int>>>dp;
int find(int i,vector<int>&nums,int prev,int status){
    if(i==nums.size())return 0;
    if(dp[i][prev+1][status+1]!=-1)return dp[i][prev+1][status+1];
    int left=0;
    if(prev==-1){
        left=1+find(i+1,nums,i,status);
    }else if(prev!=-1){
        int diff=nums[i]-nums[prev];
        if(diff<0 && (status==1 || status==-1)){
           left= 1+find(i+1,nums,i,0);

        }
        else if(diff>0 && (status==0 || status==-1)){
            left=1+find(i+1,nums,i,1);
        }
    }
     int right=find(i+1,nums,prev,status);
     return dp[i][prev+1][status+1]=max(left,right);
}
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return find(0,nums,-1,-1);
        
    }
};