class Solution {
public:
void dfs(int node,vector<vector<int>>adj,int&mini,vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            mini=min(mini,it);
            dfs(it,adj,mini,vis);
        }


    }
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       vector<vector<int>>adj(27);
    for(int i=0;i<s1.size();i++){
        adj[s1[i]-'a'].push_back(s2[i]-'a');
        adj[s2[i]-'a'].push_back(s1[i]-'a');

    }
       string str="";
      
       for(int i=0;i<baseStr.size();i++){
        int mini=baseStr[i]-'a';
         vector<int>vis(27,0);
        dfs(baseStr[i]-'a',adj,mini,vis);
        str+=(mini+'a');
       }
       return str;
       
        
        
    }
};