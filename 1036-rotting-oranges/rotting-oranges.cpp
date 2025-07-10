class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        
       
        int row[4]={-1,0,1,0};
        int col[4]={0,-1,0,1};
        int mini=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int time=it.first;
            int rows=it.second.first;
            int cols=it.second.second;
            mini=max(mini,it.first);
            for(int i=0;i<4;i++){
                int new_row=rows+row[i];
                int new_col=cols+col[i];
                if(new_row>=0 && new_col>=0 && new_row<grid.size() && new_col<grid[0].size() && grid[new_row][new_col]==1){
                    grid[new_row][new_col]=2;
                    q.push({time+1,{new_row,new_col}});
                }
            }

        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return (mini);
        
    }
};