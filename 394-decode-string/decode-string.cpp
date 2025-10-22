class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(int i=s.size()-1;i>=0;){
            if(s[i]=='['){
                string str="";
                while(!st.empty() && st.top()!="]"){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(str);
                i--;
            }
            else if(0<=(s[i]-'0') && (s[i]-'0')<=9){
                string val="";
                while(i>=0 && 0<=(s[i]-'0') && (s[i]-'0')<=9){
                    val+=s[i];
                    i--;
                }
                reverse(val.begin(),val.end());
                int value=stoi(val);
                string str=st.top();
                string temp="";
                st.pop();
                
                for(int j=0;j<value;j++){
                    temp+=str;
                }
                st.push(temp);
            }else{
                string str(1,s[i]);
                st.push(str);
                i--;
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        
    }
};