class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int>row(grid.size(),0);
        vector<int>col(grid[0].size(),0);
        int totalcount=0;
        for(int i=0;i<grid.size();i++){
            int count=0;
         for(int j=0;j<grid[0].size();j++)
         {
            if(grid[i][j]==1){
                row[i]++;
                col[j]++;
                count++;
                totalcount++;
               
            }


         }  
        
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1 && (row[i]>1 || col[j]>1)){
                    count+=1;
                }
            }
        }
        if(count>totalcount){
            return totalcount;
        }
        return count;
       
        
    }
};