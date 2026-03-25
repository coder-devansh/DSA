class DSU{
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    void unionBy(int ulp_u,int ulp_v)
    {
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            size[ulp_u]++;
            parent[ulp_v]=ulp_u;
        }
    }
    int find(int node){
        if(parent[node]==node)return node;
        return parent[node];
    }
};
class Solution {
public:
vector<int>vis;
// void dfs(int ele,vector<vector<int>>&adj,set<int>&st){
//     vis[ele]=1;
//     for(auto it:adj[ele]){
//         if(!vis[it]){
//             st.insert(it);
//             dfs(it,adj,st);

//         }
//     }
// }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<vector<int>>>mp;
      
       vis.assign(n+1,0);
        vis[0]=1;
        vis[firstPerson]=1;
        // dsu->unionBy(0,firstPerson);
        for(auto it:meetings){
            mp[it[2]].push_back({it[0],it[1]});
        }
        for(auto &it:mp){
            vector<vector<int>>&vec=it.second;
           unordered_map<int, vector<int>> adj;
            for(auto &it:vec){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            queue<int>q;
            unordered_set<int>st;
            for(auto &neigh:vec){
                int ulp_u=neigh[0];
                int ulp_v=neigh[1];
               if(vis[ulp_u]==1 && st.find(ulp_u)==st.end()){
                st.insert(ulp_u);
                q.push(ulp_u);
               }
                 if(vis[ulp_v]==1 && st.find(ulp_v)==st.end()){
                q.push(ulp_v);
                st.insert(ulp_v);
               }
            }
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                for(auto &ele:adj[it]){
                    if(!vis[ele])
                    {
                        q.push(ele);
                        vis[ele]=1;
                    }
                }
            }

        }
        vector<int>ans;
        for(int i=0;i<=n;i++){
            if(vis[i])ans.push_back(i);
        }
        return ans;

        
    }
};