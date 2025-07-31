class Solution {
public:
int row[8]={-1,-1,-1,0,1,1,1,0};
int col[8]={-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),1e9));
        queue<pair<int,int>>q;
        if(grid[0][0]==1)return -1;
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        q.push({0,0});
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first;
            int j=it.second;
            for(int k=0;k<8;k++){
                int new_row=i+row[k];
                int new_col=j+col[k];
                if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size() && grid[new_row][new_col]==0){
                    if(dist[i][j]+1<dist[new_row][new_col]){
                        dist[new_row][new_col]=dist[i][j]+1;
                        q.push({new_row,new_col});
                    }
                }
            }
        }cout<<dist[n][m];
        return dist[grid.size()-1][grid[0].size()-1]==1e9?-1:dist[grid.size()-1][grid[0].size()-1];

        
    }
};