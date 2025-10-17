class Solution {
public:
static bool compare1(string word1,string word2)
{
    return word1.size()<word2.size();

}
bool compare(int i1,int i2,vector<string>&words){
    string word1=words[i1];
    string word2=words[i2];
    int diff=word1.size()-word2.size();
    if(abs(diff)!=1)return false;
    int i=0;
    int j=0;
    while(i<word1.size()){
        if(word1[i]==word2[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(i==word1.size() && j==word2.size()) return 1;
    return false;
}
int find_length(int i,vector<string>&nums,int prev,vector<vector<int>>&dp){
    if(i==nums.size())return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int take=0;
    if(prev==-1 ||(nums[i].size()>nums[prev].size() && compare(i,prev,nums))){
        take=1+find_length(i+1,nums,i,dp);
    }
    int notTake=find_length(i+1,nums,prev,dp);
    return dp[i][prev+1]=max(take,notTake);
}
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(),nums.end(),compare1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return find_length(0,nums,-1,dp);
        
    }
};