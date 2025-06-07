struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first; // min-heap by value
        } else {
            return a.second < b.second; // if same value, higher insertion time first
        }
    }
};

class Solution {
public:

void erase(char str,string&s,vector<int>&vis,int i){
    for(int j=i;j>=0;j--){
        if(s[j]==str && !vis[j]){
            vis[j]=1;
            break;

        }
    }
}
    string clearStars(string s) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> st;
        string ans="";
        vector<int>vis(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!st.empty()){
                   vis[st.top().second]=1;
                    st.pop();
                    
                }
                continue;

            }
            
                st.push({s[i],i});
            
           
                

        }
        if(st.empty()){
            return "";
        }
       for(int i=0;i<s.size();i++){
        if(!vis[i] && s[i]!='*'){
            ans+=s[i];
        }
       }
        return ans;
      


    }
};