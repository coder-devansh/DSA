class Solution {
public:
int dfs(int node,int parent,vector<int>&parents,vector<int>&count,vector<vector<int>>&adj){
    int size=1;
    for(auto it:adj[node]){
        if(it==parent)continue;
        size+=dfs(it,node,parents,count,adj);
    }
    count[node]=size;
    return size;
}
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<parents.size();i++){
            if(parents[i]!=-1){
                adj[parents[i]].push_back(i);
            }

        }
        vector<int>count(n+1,0);//use to store the count of the node in the subtree;
        dfs(0,-1,parents,count,adj);
        long long max_score=0;
        int ans=1;
        for(int i=0;i<parents.size();i++){
            
            vector<int>&list=adj[i];
            long long score=1;
            int remaining=n-count[i];
            for(auto&ele:list){
                score*=count[ele];

            }
            if(remaining>0){
                score*=remaining;
            }
            if(score==max_score){
                ans++;

            }
            else if(max_score<score){
                max_score=score;
                ans=1;
            }

        }
        return ans;
        
    }
};