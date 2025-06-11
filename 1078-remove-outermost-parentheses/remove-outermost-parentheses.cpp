class Solution {
public:
string find(string ans){
    string temp="";
    for(int i=1;i<ans.size()-1;i++){
        temp+=ans[i];
    }
    return temp;
}
    string removeOuterParentheses(string s) {
        string ans="";
        string temp="";
        int open=0;
        int closed=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
                ans+=s[i];
            }
            if(s[i]==')'){
                closed++;
                ans+=s[i];
            }
            if(open==closed){
                temp+=find(ans);
                ans.clear();
                open=0;
                closed=0;
            }
        }
        return temp;
        
        
    }
};