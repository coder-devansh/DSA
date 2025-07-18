class Solution {
public:
vector<int>dp;
int no_of_ways(int i,string&s){
    if(i==s.size()){
        return 1;
    }
    if(s[i]=='0')return 0;
    if(dp[i]!=-1)return dp[i];
    int res=no_of_ways(i+1,s);
    if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')) )res+=no_of_ways(i+2,s);
    return dp[i]=res;


    
}
    int numDecodings(string s) {
        if(s.empty())return 0;
        dp.resize(s.size(),-1);
        return no_of_ways(0,s);
        
    }
};