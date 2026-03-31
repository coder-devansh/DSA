#define ll long long
class Solution {
public:

vector<vector<vector<int>>>dp;
ll find(int i1,int j1,int i2,vector<vector<int>>&grid){
    int j2=(i1+j1-i2);
    if(i1>=grid.size() || j1>=grid[0].size() || i2>=grid.size() || j2>=grid[0].size() || grid[i1][j1]==-1 || grid[i2][j2]==-1)return (int)-1e9;
    if(i1==grid.size()-1 && j1==grid[0].size()-1)return grid[i1][j1];
   if(dp[i1][j1][i2]!=-1)return dp[i1][j1][i2];
    int cherry=grid[i1][j1];
    if(i1!=i2){
        cherry+=grid[i2][j2];
    }
    int left=find(i1+1,j1,i2+1,grid);
    int right=find(i1,j1+1,i2,grid);
    int down=find(i1+1,j1,i2,grid);
    int up=find(i1,j1+1,i2+1,grid);
    return dp[i1][j1][i2]=max({left,right,down,up})+cherry;
    

}
    int cherryPickup(vector<vector<int>>& grid) {
        dp.resize(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(grid.size()+1,-1)));
        int ans= find(0,0,0,grid);
        if(ans<0)return 0;
        return ans;
        
        

        
    }
};