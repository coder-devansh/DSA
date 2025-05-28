class Solution {
public:
    string smallestSubsequence(string s) {
        set<char>alpha;
       
        int size=alpha.size();
        int n=s.size();
        stack<char>st;
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]]--;
            if(alpha.find(s[i])!=alpha.end()){
                continue;
            }
            while(!st.empty() && st.top()>s[i] && mp[st.top()]>0){
                alpha.erase(st.top());
                st.pop();
            }
            alpha.insert(s[i]); 
            st.push(s[i]);
                
            }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};