class Solution {
public:
bool check(string s1,string s2){
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i])continue;
        bool found=false;
        for(int j=i;j<s1.size();j+=2){
            if(s1[j]==s2[i]){
                swap(s1[j],s1[i]);
                found=true;
                break;
            }
        }
        if(!found)return false;
    }
    return s1==s2;
}
    bool checkStrings(string s1, string s2) {
        return check(s1,s2) || check(s2,s1);
        
    }
};