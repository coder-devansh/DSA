class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2==1){
            return false;
        }
        stack<int>st;
        stack<int>mp;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' && locked[i]-'0'==1)
            {
                if(!mp.empty()){
                    mp.pop();
                }else if(!st.empty()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
                if(locked[i]-'0'==0){
                    st.push(i);

                }
                if(locked[i]-'0'==1 && s[i]=='(')
                {
                    mp.push(i);
                }
                
            
        }
   while(!st.empty() && !mp.empty() && mp.top()<st.top()){
       st.pop();
       mp.pop();

   }
   if(!mp.empty()){
    return false;
   }
    return true;

      }
};