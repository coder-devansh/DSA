class Solution {
public:
int l;
vector<int>ans;
int n;
vector<vector<int>>dp;
vector<int>dp1;
void solve(int i,int count,vector<int>&sum1){
    if(count==0){
        return ;
    }
    if(i>=n){
        return ;
    }
    int take=sum1[i]+helper(i+l,count-1,sum1);
    int nottake=helper(i,count,sum1);
    if(take>=nottake){
        ans.push_back(i);
        solve(i+l,count-1,sum1);
    }else{
        solve(i+1,count,sum1);
    }
}
int helper(int index,int count,vector<int>&sum1){
   if (count == 0) {
        
        return 0;
    }
    if (index >= n) {
        return INT_MIN;
    }
    if(dp[index][count]!=-1){
        return dp[index][count];
    }
   int include = sum1[index]+helper(index + l, count -1,sum1); 
   int exclude = helper(index + 1, count,sum1);
    return dp[index][count]=max(include, exclude);
 
    
}
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        n=nums.size();
    vector<int>prefix(nums.size(),0);
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        prefix[i]=sum;
    }
    l=k;
    vector<int>sum1(nums.size(),0);
    dp.resize(nums.size(),vector<int>(3+1,-1));
    sum1[0]=prefix[k-1];
    for(int i=1;i<=nums.size()-k;i++){
        int subarray_sum=prefix[i+k-1]-prefix[i-1];
        sum1[i]=subarray_sum;
        }
        
        solve(0,3,sum1);
    return ans;


        
    }
};