class Solution {
public:
map<string,int>mp;
vector<int>memo;
bool find(int i,string s){
    if(i==s.size()){
        return true;
    }
    if(memo[i]!=-1)return memo[i];
    for(int end=i+1;end<=s.size();end++){
        string sub=s.substr(i,end-i);
        if(mp.find(sub)!=mp.end() && find(end,s)) return memo[i]=true;;
    }
    return memo[i]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {

        memo.resize(s.size()+1,-1);
        for(auto it:wordDict){
            mp[it]++;
        }
        return find(0,s);
        
    }
};