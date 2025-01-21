class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum=0;
        for(int j=0;j<grid[0].size();j++){
            firstRowSum+=grid[0][j];
        }
        long long secondRowSum=0;
        long long minimumsum=LONG_LONG_MAX;
        for(int j=0;j<grid[0].size();j++){
            firstRowSum-=grid[0][j];
            minimumsum=min(minimumsum,max(firstRowSum,secondRowSum));
            secondRowSum+=grid[1][j];

        }
        return minimumsum;
        
    }
};