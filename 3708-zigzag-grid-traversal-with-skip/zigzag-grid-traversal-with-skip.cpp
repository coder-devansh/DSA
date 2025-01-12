class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>arr;
        int i=0;
        int left=0;
        int right=grid[0].size()-1;
        int take=0;
      for(int i=0;i<grid.size();i++){
         if(i%2!=0){
             for(int j=grid[i].size()-1;j>=0;j--){
                 arr.push_back(grid[i][j]);
             }
         }else{
             for(int j=0;j<grid[i].size();j++){
                 arr.push_back(grid[i][j]);
             }
         }
      }
        vector<int>temp;
        for(int i=0;i<arr.size();i+=2){
            temp.push_back(arr[i]);
            
        }
        return temp;
        
    }
};