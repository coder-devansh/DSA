class Solution {
public:
vector<int>findmin(int n,vector<vector<int>>edges){
    if(n<=2){
        return {n-1,n-1};
    }
    queue<int>q;
    int height=0;
    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
        indegree[it[1]]++;
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==1) q.push(i);
    }
    int lastlevelsize=0;
    while(!q.empty()){
        int size=q.size();
        lastlevelsize=0;
        
        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();
            for(auto node:adj[it])
            {
                indegree[node]--;
                if(indegree[node]==1){
                    q.push(node);
                }

            }
            

        }
        height+=1;
        lastlevelsize=size;
    }
    height-=1;
    int diam=2*height;
    if(lastlevelsize>1){
        height+=1;
        diam+=1;
    }
    return {height,diam};

}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int>tree1=findmin(edges1.size()+1,edges1);
        vector<int>tree2=findmin(edges2.size()+1,edges2);
        return max(max(tree1[1],tree2[1]),tree1[0]+tree2[0]+1);
        
    }
};