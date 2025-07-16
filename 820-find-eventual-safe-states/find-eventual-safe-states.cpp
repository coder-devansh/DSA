class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int>outdegree(graph.size()+1,0);
        vector<int>indegree(graph.size()+1,0);
        vector<vector<int>>adj(graph.size()+1);
        for(int i=0;i<graph.size();i++){
           for(auto it:graph[i]){
            adj[it].push_back(i);
            outdegree[i]++;
            indegree[i]++;
           }
           
        }
         vector<int>ans;
        map<int,int>terminal_nodes;
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(outdegree[i]==0){
                q.push(i);
                ans.push_back(i);
                terminal_nodes[i]++;
            }
        }
       
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                    continue;
                }
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

         
        

        
    }
};