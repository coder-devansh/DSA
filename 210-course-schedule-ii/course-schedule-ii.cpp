class Solution {
public:
bool found=false;
bool hasCycle;
void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st,vector<bool>&inrecursion){
   
   vis[node]=1;
   inrecursion[node]=true;
    for(auto it:adj[node])
    {
        if(inrecursion[it]==true){
            hasCycle=true;
            return;
        }
        if(!vis[it])
        {
            dfs(it,adj,vis,st,inrecursion);
            
        }
        
        
        }
    
    inrecursion[node]=false;
    st.push(node);
}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        vector<bool>inrecursion(numCourses,false);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            
        }
        vector<int>vis(numCourses,0);
        stack<int>st;
    
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
            {
                dfs(i,adj,vis,st,inrecursion);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
       if(hasCycle==true){
        return {};

       }
    
        return ans;
        
    }
};