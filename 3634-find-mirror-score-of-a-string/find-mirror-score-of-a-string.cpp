class Solution {
public:

    long long calculateScore(string s) {
        long long score=0;
        vector<bool>used(s.size(),false);
        unordered_map<char,stack<int>>mp;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            char mirror='a'+('z'-ch);
            if(!mp[mirror].empty() && mp.find(mirror)!=mp.end()){
                int j=mp[mirror].top();
                if(!used[j] && j<i){
                    score+=i-j;
                    used[i]=true;
                    used[j]=true;
                    mp[mirror].pop();
                }
            }
            if(!used[i])
            {
                mp[s[i]].push(i);
            }
        }
        return score;
        
    }
};