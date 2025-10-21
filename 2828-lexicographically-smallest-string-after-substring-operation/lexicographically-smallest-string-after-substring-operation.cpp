class Solution {
public:
    string smallestString(string s) {
        string temp="";
        int ops=0;
        int i=0;
        while(i<s.size()){
            if(s[i]!='a'){
                s[i]=s[i]-1;
                ops=1;
                i++;
                continue;

            }
            if(i==s.size()-1 && ops==0 && s[i]=='a'){
                s[i]='z';
                break;
            }
            if(s[i]=='a' && ops==1)break;
            i++;

        }
        
        return s;

        
    }
};