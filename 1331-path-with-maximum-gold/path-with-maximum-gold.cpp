class Solution {
public:
int find_max(int i,int j,vector<vector<int>>&grid){
    if( i<0 || j<0 || i>=grid.size()  || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==-1){
        return 0;
    }
    int dir[4]={-1,0,1,0};
    int dic[4]={0,-1,0,1};
    int val=grid[i][j];
    grid[i][j]=-1;
    int maxi=0;
    for(int k=0;k<4;k++){
        int row=i+dir[k];
        int col=j+dic[k];
        maxi=max(maxi,find_max(row,col,grid));

    }
    grid[i][j]=val;
    return maxi+grid[i][j];


}
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                maxi=max(maxi,find_max(i,j,grid));
            }
        }
        return maxi;
        
    }
};