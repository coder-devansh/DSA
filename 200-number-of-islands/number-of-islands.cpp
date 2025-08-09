class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
       int rows[4]={-1,0,1,0};
       int cols[4]={0,-1,0,1};
       int max_count=0;
       int count=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
       for(int i=0;i<grid.size();i++)
       {
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='1' && !vis[i][j]){
                q.push({i,j});
                 vis[i][j]=1;
                 count++;
                
        while(!q.empty()){
        
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        
       
        bool found=false;
        for(int i=0;i<4;i++){
            int new_row=row+rows[i];
            int new_col=col+cols[i];
            if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size() && !vis[new_row][new_col] && grid[new_row][new_col]=='1'){
                vis[new_row][new_col]=1;
                q.push({new_row,new_col});
               
            }
    }
                
}

            }
            
       }
    }
       return count;
      
        
    }
};