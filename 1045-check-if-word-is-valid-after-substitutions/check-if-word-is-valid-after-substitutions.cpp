class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       vector<char>vec={'b','a'};
       for(int i=0;i<s.size();i++){
        if(s[i]=='c'){
            int count=1;
            int k=0;
            while(!st.empty() && k<vec.size() && st.top()==vec[k] )
            {
                st.pop();
                k++;
                count++;
            }
            if(count!=3)return false;

        }else{
            st.push(s[i]);
        }
       }
       if(st.empty())return true;
       return false;
        
    }
};