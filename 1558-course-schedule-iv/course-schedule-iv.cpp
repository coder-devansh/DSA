class Solution {
public:

void bfs(int i,vector<vector<int>>&adj,vector<vector<bool>>&isReachable){
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        for(auto &ngbr:adj[it]){
            if(!isReachable[i][ngbr]){
                 isReachable[i][ngbr]=true;
                q.push(ngbr);
                }
            }

    }
}
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       vector<vector<int>>adj(numCourses);
       vector<vector<bool>>isReachable(numCourses,vector<bool>(numCourses,false));
        vector<bool>ans;
       if(prerequisites.size()==0){
        vector<bool>result(numCourses,false);
        return result;

       }
        for(auto &it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
       
        for(int i=0;i<numCourses;i++){
            bfs(i,adj,isReachable);
         }
        for(auto &it:queries){
            ans.push_back(isReachable[it[0]][it[1]]);
        }
        return ans;
        
    }
};