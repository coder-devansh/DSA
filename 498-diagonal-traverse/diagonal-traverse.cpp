class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int count=1;
        int i=0;
        int j=0;
        vector<int>temp;
        while(i<mat.size() && j<mat[0].size()){
            if(count%2!=0){
                while(i>=0 && j<mat[0].size()){
                    temp.push_back(mat[i][j]);
                    i--;
                    j++;


                }
                 count++;               
                 if(j==mat[0].size()){
                    i+=2;
                    j--;
                    continue;
                 }
                 i++;
                
               
            }
            else{
                while(i<mat.size() && j>=0){
                    temp.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                 count++;
                if(i==mat.size()){
                    j+=2;
                    i--;
                    continue;
                }
                
                j++;

            }
        }
        return temp;
        
    }
};