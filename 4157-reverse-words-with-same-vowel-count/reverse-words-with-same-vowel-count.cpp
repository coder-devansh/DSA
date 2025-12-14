class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int vowel=0;
        int i=0;
        while(i<s.size()){
            if(i==0){
                string str="";
                while('a'<=s[i] && s[i]<='z'){
                if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i'){
                    vowel++;
                    
                }
                    str+=s[i];
                   i++;
            }
                 ans+=str;
                i++;
                
            }else{
                int new_vowel=0;
                string str="";
                while('a'<=s[i] && s[i]<='z'){
                if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i'){
                    new_vowel++;
                   
                    
                }
                    str+=s[i];
                    i++;
                }
                i++;
                if(new_vowel==vowel){
                    reverse(str.begin(),str.end());
                    ans+=" ";
                    ans+=str;
                }else{
                    ans+=" ";
                    ans+=str;
                    
                }
                
                
            }
            
        }
        return ans;
        
    }
};