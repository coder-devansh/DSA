class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        int count1=0;
        for(char ch='a';ch<='z';ch++){
            char letter=(char)(ch-32);
            if(mp.find(ch)!=mp.end() && mp.find(letter)!=mp.end()){
                count1++;
            }
        }
        return count1;
        
        
        
    }
};