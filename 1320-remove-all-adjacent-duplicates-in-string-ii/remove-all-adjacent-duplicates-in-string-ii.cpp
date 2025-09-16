class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>>st;
       for(auto it:s){
        if(!st.empty() && st.top().first==it){
            st.top().second++;
            if(st.top().second==k){
                st.pop();
            }
        }
       else{
        st.push({it,1});
       }
    }
    string result="";
    while(!st.empty()){
        auto [ch,cnt]=st.top();
        st.pop();
        result.append(cnt,ch);
    }
    reverse(result.begin(),result.end());
    return result;
    
        
    }
};