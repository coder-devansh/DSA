class Solution {
public:
vector<long long >dp;
long long Points(int i,vector<vector<int>>&questions){
    if(i>=questions.size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    long long  left=questions[i][0]+Points(i+questions[i][1]+1,questions);
    long long  right=Points(i+1,questions);
    return dp[i]=max(left,right);
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();

        dp.resize(1e5,-1);
        
        return Points(0,questions);
        
    }
};