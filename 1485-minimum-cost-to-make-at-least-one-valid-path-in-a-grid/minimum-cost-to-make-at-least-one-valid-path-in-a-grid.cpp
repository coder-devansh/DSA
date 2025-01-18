struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};


class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        unordered_map<pair<int,int>,vector<pair<pair<int,int>,int>>,pair_hash>adj;
        map<int,vector<int>>mp;
        mp[1]={0,1};
        mp[2]={0,-1};
        mp[3]={1,0};
        mp[4]={-1,0};
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                for(int k=0;k<4;k++){
                    int dir=i+dr[k];
                    int dic=j+dc[k];
                    if(dir>=0 && dir<grid.size() && dic>=0 && dic<grid[0].size()){
                      auto it=mp[grid[i][j]];
                      if(it[0]==dr[k] && it[1]==dc[k]){
                        adj[{i,j}].push_back({{dir,dic},0});
                      }else{
                        adj[{i,j}].push_back({{dir,dic},1});

                      }
                    }
                }

            }
        }
        int n=grid.size();
        int m=grid[0].size();
        int mini=INT_MAX;
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
      
        q.push({0,{0,0}});
        dist[0][0]=0;
       
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
         vis[0][0]=1;
        while(!q.empty()){
           auto [ed,node]=q.top();
           q.pop();
           int x=node.first;
           int y=node.second;
           if(ed>dist[x][y])continue;
           
            
            for(auto& [point,edw]:adj[node])
            {
               int nx=point.first;
               int ny=point.second;
               
                if(dist[x][y]+edw<dist[nx][ny])
                {
                    dist[nx][ny]=dist[x][y]+edw;
                    q.push({dist[nx][ny],{nx,ny}});
                }

            }
        }
        return dist[n-1][m-1];
        
    }
};