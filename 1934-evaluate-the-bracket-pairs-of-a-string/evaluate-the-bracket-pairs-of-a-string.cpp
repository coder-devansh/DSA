class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp;
        for(auto it:knowledge){
            mp[it[0]]=it[1];
        }
        queue<char>st;
        string ans="";
        bool brac=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                brac=true;
            }
            else if(s[i]==')'){
                string val="";
                while(!st.empty()){
                    if(st.front()!='('){
                        val+=st.front();
                    }
                    st.pop();
                    brac=false;
                }
               
                if(mp.find(val)!=mp.end())
                {
                    ans+=mp[val];
                }else{
                    ans+='?';
                }
            }
            else {
                if(brac){
                    st.push(s[i]);
                }
                if(!brac){
                    ans+=s[i];
                }
            }

        }
        return ans;

        
    }
};