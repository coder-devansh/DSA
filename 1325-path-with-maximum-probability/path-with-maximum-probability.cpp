class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dis(n,-1e9);
          queue<int>q;
         vector<pair<double,double>>adj[n];
         int i=0;
         for(auto it:edges){
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i++;

         }
         dis[start_node]=1.0;
         q.push(start_node);
         while(!q.empty()){
           auto it=q.front();
           int node=it;
           q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                double edw=it.second;
                if(dis[node]*edw>dis[adjnode])
                {
                    dis[adjnode]=dis[node]*edw;
                    q.push(adjnode);
                }
            }
           

         }
         if(dis[end_node]<=-1e9){
            return 0.00000;
         }
 return dis[end_node];


        
    }
};