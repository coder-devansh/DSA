#define ll long long
class Solution {
public:

vector<vector<vector<int>>>dp;
// memoization dp;
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
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(grid.size()+1,-(int)1e9)));
        dp[n-1][m-1][n-1]=(grid[n-1][m-1]);
        int ans= find(0,0,0,grid);
        for(int i1=n-1;i1>=0;i1--){
            for(int j1=m-1;j1>=0;j1--){
                for(int i2=n-1;i2>=0;i2--){
                    int j2=(i1+j1-i2);
           if(j2<0 || j2>=m)continue;
           if(grid[i1][j1]==-1 || grid[i2][j2]==-1)continue;
           if(i1 == n-1 && j1 == m-1) continue;
            int cherry=grid[i1][j1];
    if(i1!=i2){
        cherry+=grid[i2][j2];
    }
                    int left=dp[i1+1][j1][i2+1];
                    int right=dp[i1][j1+1][i2];
                    int down=dp[i1+1][j1][i2];
                    int up=dp[i1][j1+1][i2+1];
                dp[i1][j1][i2]=max({left,right,down,up})+cherry;

                }
            }
        }
        return max(0,dp[0][0][0]);
        // tabulation dp

        
        
        

        
    }
};