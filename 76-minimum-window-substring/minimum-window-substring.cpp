class Solution {
public:
    string minWindow(string s, string t) {
       map<char,int>mp;
       for(auto it:t){
        mp[it]++;
       }
       int left=0;
       int right=0;
       int start=0;
       int minLength=INT_MAX;
       int word=t.size();
       while(right<s.size()){
        if(mp.find(s[right])!=mp.end()){
          
            if(mp[s[right]]>0){
                word--;
            }
              mp[s[right]]--;
        }
        while(word==0){
            if(right>=left){
            int len=right-left+1;
            if(minLength>len){
                minLength=len;
                start=left;
            }
            }
            char leftChar=s[left];
            if(mp.find(leftChar)!=mp.end()){
                mp[leftChar]++;
                if(mp[leftChar]>0){
                    word++;
                }
            }
            left++;

        }
        right++;
        
       }
       if(minLength==INT_MAX)return "";
       return s.substr(start,minLength);
        
    }
};