class Solution {
public:
int row[4]={-1,0,1,0};
int col[4]={0,1,0,-1};
int count;
void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&vis){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int new_r=i+row[k];
        int new_c=j+col[k];
        if(new_r>=0 && new_r<grid.size() && new_c>=0 && new_c<grid[0].size() && !vis[new_r][new_c] && grid[new_r][new_c]>0){
            count=count+grid[new_r][new_c];
            dfs(grid,new_r,new_c,vis);
        }
    }
  
}
    int findMaxFish(vector<vector<int>>& grid) {
      
        int maxi=INT_MIN;
          vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    count=grid[i][j];
                  
                    dfs(grid,i,j,vis);
                   maxi=max(maxi,count);
                }
            }
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
        
    }
};