class Solution {
public:
vector<vector<int>>dp;
bool find(int i,string s,int count_open ){
    if(count_open<0)return false;
    if(i==s.size()){
        return (count_open==0);
    }
   if(dp[i][count_open]!=-1)return dp[i][count_open];
   
    if(s[i]=='('){
         return dp[i][count_open]=find(i+1,s,count_open+1);
    }
    if(s[i]==')'){
        return dp[i][count_open]=find(i+1,s,count_open-1);
    }


        bool c=find(i+1,s,count_open+1);
        bool d=find(i+1,s,count_open-1);
        bool e=find(i+1,s,count_open);
    
    return dp[i][count_open]=c||d||e;
}
    bool checkValidString(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return find(0,s,0);
        
    }
};