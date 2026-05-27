class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,bool>mp;
        int count1=0;

        for(auto it:word){
            if(it>='A' && it<='Z' && mp.find(it)==mp.end()){
                char new_c=(char)(it-'A'+97);
                if(mp.find(new_c)!=mp.end())mp[new_c]=true;

            }
            if(it>='a' && it<='z' && mp[it]==true){
                mp[it]=false;
            }
            mp[it]=false;

        }
        for(auto it:mp){
            if(mp[it.first]==true)count1++;
        }
        return count1;
        
    }
};