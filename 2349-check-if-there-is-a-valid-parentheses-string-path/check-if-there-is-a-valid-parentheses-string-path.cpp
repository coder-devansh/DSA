class Solution {
public:
vector<vector<vector<int>>>dp;
bool find(int i,int j,vector<vector<char>>&grid,int balance){
    if(i==grid.size()-1 && j==grid[0].size()-1){
        if(grid[i][j]==')' && (balance)==1)return true;
        return false;
    }
    if(i>=grid.size() || j>=grid[0].size())return false;
    bool left=false;
    bool right=false;
    if(dp[i][j][balance]!=-1)return dp[i][j][balance];
    
    if(grid[i][j]==')'){
        if(balance>0){
        left=find(i+1,j,grid,balance-1);
        right=find(i,j+1,grid,balance-1);
        }
        return dp[i][j][balance]=left || right;
    }
   else{
        left=find(i+1,j,grid,balance+1);
        right=find(i,j+1,grid,balance+1);
        return dp[i][j][balance]=left || right;
    }
    

}
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(m+n,-1)));
        return find(0,0,grid,0);
        
    }
};