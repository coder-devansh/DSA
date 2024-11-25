class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>adj={
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        string s="";
        string target="123450";
        for(auto it:board){
            for(auto j:it){
                s+=to_string(j);
            }
        }
       set<string>st;
        st.insert(s);
        queue<pair<string,int>>q;
        q.push({s,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.second;
            
            string curr=it.first;
            if(curr==target){
                return node;
            }
            int x=curr.find('0');
            for(int it:adj[x])
            {
                string t=curr;
                swap(t[it],t[x]);
                if(st.find(t)==st.end()){
                    st.insert(t);
                    q.push({t,node+1});
                }
            }

        }
        return -1;
        
    }
};