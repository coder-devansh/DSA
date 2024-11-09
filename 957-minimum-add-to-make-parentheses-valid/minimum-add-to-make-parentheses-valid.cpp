class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<string >ans;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            {
                ans.push_back("(");
            }
            else if(s[i]==')')
            {

                if(!ans.empty() &&  ans[ans.size()-1]=="("){
                  
                        ans.pop_back();

                    }
                
                    else{
                    ans.push_back(")");
                }
               
            }
        }
        return ans.size();
        
    }
};