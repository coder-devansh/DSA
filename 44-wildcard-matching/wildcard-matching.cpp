class Solution {
public:
bool checkstars(string&p,int j){
   while(j>=0){
    if(p[j]!='*'){
        return false;
    }
    j--;

   }
   return true;
}
vector<vector<int>>dp;
bool find(int i,int j,string&s,string&p){
    if(i<0 && j<0){
        return true;
    }
    if(j<0 && i>=0){
        return false;
    }
    if(i<0 && j>=0 )
    {
        return checkstars(p,j);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   

    if(s[i]==p[j] || p[j]=='?')
    {
        return dp[i][j]=find(i-1,j-1,s,p);
    }
    else if(p[j]=='*')
    {
        return dp[i][j]=find(i-1,j,s,p) || find(i,j-1,s,p);
    }
    return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
        dp.resize(s.size(),vector<int>(p.size(),-1));
        
       return  find(s.size()-1,p.size()-1,s,p);
        
    }
};