class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>>prefix;
        for(int j=0;j<grid[0].size();j++){
            for(int i=1;i<grid.size();i++){
                grid[i][j]+=grid[i-1][j];

            }
        }
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            temp.push_back(grid[i][0]);
            for(int j=1;j<grid[0].size();j++){
                temp.push_back(grid[i][j]+temp[temp.size()-1]);
            }
            prefix.push_back(temp);
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(prefix[i][j]<=k)count++;
            }
        }
        return count;
        
        
    }
};