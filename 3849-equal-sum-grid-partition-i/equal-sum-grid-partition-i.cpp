#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& chr) {
        vector<vector<long long>>grid(chr.size(),vector<ll>(chr[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=chr[i][j];
            }
        }
        for(int j=0;j<grid[0].size();j++){
            for(int i=1;i<grid.size();i++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==(grid[n-1][m-1]-grid[i][j]))return true;
            }
        }
        return false;
        
    }
};