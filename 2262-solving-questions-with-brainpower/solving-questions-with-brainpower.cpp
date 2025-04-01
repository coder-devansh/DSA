long long dp[100000];

class Solution {
public:


long long  find(int i,vector<vector<int>>&questions,int score){
   if(i>=questions.size()){
    return 0;
   }
   if(dp[i]!=-1){
    return dp[i];
   }
    
    long long  right=questions[i][0]+find(i+questions[i][1]+1,questions,score);
    long long  left=find(i+1,questions,score);
   
    return dp[i]=max(left,right);
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
      memset(dp, -1, n*sizeof(long long));
            long long ans=find(0,questions,0);
        
    
        return ans;
        
    



        

        
    }
};