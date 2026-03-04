class Solution {
public:
bool check(int row,int col,vector<vector<int>>&mat){
    for(int i=0;i<mat.size();i++){
        if(i!=row && mat[i][col]==1){
            return false;
        }
    }
    for(int j=0;j<mat[0].size();j++){
        if(j!=col && mat[row][j]==1)return false;
    }
    return true;
}
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    if(check(i,j,mat))count++;
                }
            }
        }
        return count;
        
    }
};