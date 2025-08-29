class Solution {
public:
bool isNUm(char ch){
    if(0<=(ch-'0') && (ch-'0')<=9){
        return true;
    }
    return false;
}
bool isAlpha(char ch){
    if(ch>='a' && ch<='z'){
        return true;
    }
    return false;
}
bool isvalid(string str){
    int i=0;
    int j=str.size()-1;
    while(i<j){
        if(str[i]!=str[j])return false;
        i++;
        j--;
    }
    return true;
}
    bool isPalindrome(string str) {
        string new_str="";
        for(int i=0;i<str.size();i++){
            if(isNUm(str[i])){
                new_str+=str[i];

            }else if(isAlpha(tolower(str[i]))){
                new_str+=tolower(str[i]);

            }
        }
        
        return isvalid(new_str);
        
    }
};