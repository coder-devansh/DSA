class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<int>dist(n,1e9);
       vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
         queue<pair<int,pair<int,int>>>q;
          q.push({-1,{src,0}});
          int minValue=INT_MAX;
          vector<int>vis(n,0);
          vis[src]=1;
          dist[src]=0;
          while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int distance=it.second.second;
            if(stops>k)continue;
            for(auto it:adj[node]){
               int flight_node=it.first;
               int flight_distance=it.second;
               
               if(distance+flight_distance<dist[flight_node] && stops+1<=k){
                dist[flight_node]=distance+flight_distance;
                q.push({stops+1,{flight_node,dist[flight_node]}});

    }

            }

          }
          return dist[dst]==1e9?-1:dist[dst];
      
        
    }
};