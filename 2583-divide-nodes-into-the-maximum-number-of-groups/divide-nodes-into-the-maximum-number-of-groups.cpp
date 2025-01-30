class Solution {
public:
   void  isBiparit(vector<vector<int>>&adj,int node,vector<int>&color,vector<int>&vis,int clr)
{   vis[node]=1;
    color[node]=clr;
    for(auto it:adj[node]){
        if(!vis[it]){
           
            isBiparit(adj,it,color,vis,1-clr);
        }
    }
    
}
int getpath(vector<vector<int>>&adj,int src,int n){
    queue<int>q;
    vector<int>vis(n+1,0);
    vis[src]=1;
    q.push(src);
    int distance=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                    
                }
            }
            
        }
        distance++;
    }
    return distance;
}
int find(vector<vector<int>>&adj,int node,vector<int>&distance,vector<int>&vis){
    stack<int> st;
        st.push(node);
        vis[node] = 1;
        int max_groups = distance[node];

        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            for (auto neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    st.push(neighbor);
                    max_groups = max(max_groups, distance[neighbor]);
                }
            }
        }
        cout<<max_groups;
        return max_groups;
    
}
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>color(n+1,-1);
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){

               isBiparit(adj,i,color,vis,0);
        }
        }
       for(int i=1;i<=n;i++){
         
            for(auto it:adj[i])
            {
               if(color[it]==color[i])
                {
                    return -1;
                }
            }
         }
        vis.resize(n+1,0);
         queue<int>q;
         vector<int>distance(n+1,0);
         for(int i=1;i<=n;i++){
            distance[i]=getpath(adj,i,n);
         }
         vector<int>visited(n+1,0);
        int ans=-1;
        int max_groups=0;
          
         for(int i=1;i<=n;i++){
            if(!visited[i])
            {
                ans=find(adj,i,distance,visited);
              
                max_groups+=ans;
            }
         }
         return max_groups;

       
      
       
        
    }
};