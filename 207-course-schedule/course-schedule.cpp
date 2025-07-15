class Solution {
public:
vector<int>recursiontrack;
bool checkCycle(int node,vector<vector<int>>&adj,int parent,vector<int>&vis){
    vis[node]=1;
    recursiontrack[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(checkCycle(it,adj,node,vis))return true;
        }else if(recursiontrack[it]){
            return true;
        }
    }
    recursiontrack[node]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            

        }
        vector<int>vis(numCourses,0);
        recursiontrack.resize(numCourses+1,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,-1,vis))return false;

            }
        }
        return true;
        
        

        
    }
};