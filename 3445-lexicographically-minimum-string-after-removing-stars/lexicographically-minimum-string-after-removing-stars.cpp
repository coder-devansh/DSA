// struct Compare {
//     bool operator()(pair<int, int>& a, pair<int, int>& b) {
//         if (a.first != b.first) {
//             return a.first > b.first; // min-heap by value
//         } else {
//             return a.second < b.second; // if same value, higher insertion time first
//         }
//     }
// };

class Solution {
public:
    string clearStars(string s) {
      priority_queue<pair<int, int>, vector<pair<int, int>>> st;
        string ans="";
        vector<int>vis(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!st.empty()){
                   s[st.top().second]='*';
                    st.pop();
                    
                }
                continue;

            }
            
                st.push({-s[i],i});
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