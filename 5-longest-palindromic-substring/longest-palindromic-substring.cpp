class Solution {
public:
bool isPalindrome(int i,int j,string&str){
    while(i<j)
    {
        if(str[i]!=str[j])return false;
        i++;
        j--;

    }
    return true;
}
    string longestPalindrome(string s) {
        int maxlen=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(i,j,s)){
                int len=j-i+1;
                if(maxlen<len){
                    start=i;
                    maxlen=len;
                }

                }
            }
        }
        return s.substr(start,maxlen);
        
    }
};