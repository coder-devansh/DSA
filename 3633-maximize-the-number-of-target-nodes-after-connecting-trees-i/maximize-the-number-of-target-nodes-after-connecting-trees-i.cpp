class Solution {
public:
int dfs(int node,vector<vector<int>>&adj,int k,int parent){
    if(k<0){
        return 0;
    }
    int sum=1;
    for(auto it:adj[node]){
        if(it!=parent){   // here we check whether node is visited or not
             sum+=dfs(it,adj,k-1,node);

        }
       
    }
    return sum;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int v=edges2.size();
        vector<vector<int>>adj(n+1);
        vector<vector<int>>adj1(v+1);
        for(auto it:edges1){ // It make me a tree1;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){   // it make me a tree2
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }vector<int>ans;

        
        for(int i=0;i<=n;i++){
           ans.push_back (dfs(i,adj,k,-1)); // here I calculate our dfs

           
            
        }
        vector<int>result;
        int maxi=0;
        for(int i=0;i<=v;i++){
           maxi=max(maxi,(dfs(i,adj1,k-1,-1))); // here I calculate our answer array 
           
            
        }
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
        for(auto it:result) cout<<it<<" ";
        vector<int>final_ans;
        for(int i=0;i<=n;i++){
            final_ans.push_back(ans[i]+maxi);

        }
                return final_ans;
        
    }
};