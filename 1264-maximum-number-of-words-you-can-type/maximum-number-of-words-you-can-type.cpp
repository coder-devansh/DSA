class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char,int>mp;
        for(auto it:brokenLetters){
            mp[it]++;
        }
        int ans=0;
        for(int i=0;i<text.size();){
            map<char,int>mp1;
            while(i<text.size() && text[i]!=' '){
                mp1[text[i]]++;
                i++;
            }
            i++;
            bool found=false;
            for(auto it:mp1){
                if(mp.find(it.first)!=mp.end()){
                   found=true;
                }
            }
            if(!found)ans++;
        }
        return ans;
        

        
    }
};