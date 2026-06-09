class Solution {
public:
bool Detect(vector<int>&indegree,vector<vector<int>>&adj){
    queue<int>q;
    vector<int>ans;
    for(int i=0;i<adj.size();i++){
        if(indegree[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        for(auto ele:adj[it]){
            indegree[ele]--;
            if(indegree[ele]==0){
                ans.push_back(ele);
                q.push(ele);
            }
        }
    }
    if(ans.size()==adj.size())return false;
    return true;
}
vector<vector<int>>dp;
void find_color(int i,string &colors,vector<vector<int>>&adj,vector<int>&vis){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            find_color(it,colors,adj,vis);
            

        }

        for(int c=0;c<=26;c++){
    dp[i][c] = max(dp[i][c], dp[it][c]);
    }
    }
    dp[i][colors[i]-'a']++;
   
    
}

    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n=colors.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        dp.resize(n+1,vector<int>(27,0));
        vector<int>vis(n+1,0);
        int max_value=INT_MIN;
        vector<int>temp=indegree;
        if(Detect(indegree,adj))return -1;
        for(int i=0;i<colors.size();i++){
            if(temp[i]!=0)continue;
            find_color(i,colors,adj,vis);
        }
        for(int i=0;i<colors.size();i++){
            for(int j=0;j<=26;j++){
                max_value=max(max_value,dp[i][j]);
            }
        }
        return max_value;
    

        
        
    }
};