class Solution {
public:
int empty=1;
int solve(int i,int j,vector<vector<int>>grid,int empty){
     if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1)return 0;
    if(grid[i][j]==2){
        if(empty==0)return 1;
        return 0;
    }
    int dir[4]={-1,0,1,0};
    int dic[4]={0,-1,0,1};
    int val=grid[i][j];
    grid[i][j]=-1;
    int sum=0;
    for(int k=0;k<4;k++){
        sum+=solve(i+dir[k],j+dic[k],grid,empty-1);
    }
    grid[i][j]=val;
    return sum;
   
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        for(auto it:grid){
            for(auto i:it){
                if(i==0)empty++;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return solve(i,j,grid,empty);
                }
            }
        }
        return 0;
        
    }
};