class Solution {
public:
int find_common(int i,int j,string word1,string word2,vector<vector<int>>&dp){

   if(i==word1.size() || j==word2.size())return 0;
   if(dp[i][j]!=-1)return dp[i][j];
    if(word1[i]==word2[j]){
        return dp[i][j]=1+find_common(i+1,j+1,word1,word2,dp);
    }

    return dp[i][j]=max(find_common(i+1,j,word1,word2,dp),find_common(i,j+1,word1,word2,dp));
    
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        int length= find_common(0,0,word1,word2,dp);
        return word1.size()-length+word2.size()-length;
        
    }
};