class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        for(auto it:tickets){
            adj[it[0]].insert(it[1]);
        }
        stack<string>st;
        vector<string>ans;
        st.push("JFK");
        while(!st.empty())
        {
            string src=st.top();
            if(adj[src].size()==0)
            {
                st.pop();
                ans.push_back(src); 
                       }
                       else{
                        auto dst=adj[src].begin();
                        st.push(*dst);
                        adj[src].erase(dst);

                       }          
                        
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};