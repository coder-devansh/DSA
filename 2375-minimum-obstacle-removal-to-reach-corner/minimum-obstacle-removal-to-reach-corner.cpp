class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),1e9));
        queue<pair<pair<int,int>,int>>q;
        
      
        if(grid[0][0]==1){
          q.push({{0,0},1});
          dis[0][0]=1;
        }else{
            q.push({{0,0},0});
            dis[0][0]=0;


        }
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
           int r=it.first.first;
           int c=it.first.second;
           int dist=it.second;
           for(int i=0;i<4;i++){
            int new_r=r+row[i];
            int new_c=c+col[i];
            if(new_r>=0 && new_r<grid.size() && new_c>=0 && new_c<grid[0].size())
            {
                if(dis[r][c]+grid[new_r][new_c]<dis[new_r][new_c])
                {
                    dis[new_r][new_c]=dis[r][c]+grid[new_r][new_c];
                    q.push({{new_r,new_c},dis[new_r][new_c]});
                }
            }
           }
            

        }
        return dis[grid.size()-1][grid[0].size()-1];
            }
};