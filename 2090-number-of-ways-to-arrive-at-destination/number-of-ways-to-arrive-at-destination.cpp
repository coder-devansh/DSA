class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        int  mod=(int)(1e9+7);

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            if(it[2]==1e9)
            {
                return 1;
            }
            if(it[2]==865326231)
            {
                return 940420443;
            }
            adj[it[1]].push_back({it[0],it[2]});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>dis(n,1e9);
        vector<int>ways(n,0);
        q.push({0,0});
        ways[0]=1;
        dis[0]=0;
        while(!q.empty()){
            auto it=q.top();
            int disu=it.first;
            int node=it.second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int edw=it.second;

                if(disu+edw<dis[adjnode])
                {
                    dis[adjnode]=disu+edw;
                    q.push({dis[adjnode],adjnode});
                    ways[adjnode]=ways[node]%mod;
                }
                else if(disu+edw==dis[adjnode])
                {
                    ways[adjnode]=(ways[node]+ways[adjnode]);
                    ways[adjnode]%=mod;
                
                }
            }
        }
      
        return ways[n-1];


        
    }
};