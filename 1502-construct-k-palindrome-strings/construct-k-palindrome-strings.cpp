class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k){
            return false;
        }
        map<char,int>mp;
        long long count=0;
        for(auto it:s){
            mp[it]++;

        }
        for(auto it:mp){
            if(it.second%2!=0){
                count++;
            }
        }
        if(count>k){
            return false;
        }
        return true;
        
    }
};