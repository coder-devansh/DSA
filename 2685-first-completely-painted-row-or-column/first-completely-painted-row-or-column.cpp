class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    map<int,int>rows;
    map<int,int>cols;
        vector<int>row(mat.size(),0);
        vector<int>col(mat[0].size(),0);
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            rows[mat[i][j]]=i;
            cols[mat[i][j]]=j;


        }
       }
       for(int i=0;i<arr.size();i++){
        row[rows[arr[i]]]++;
        if(row[rows[arr[i]]]==mat[0].size()){
            return i;
        }
        col[cols[arr[i]]]++;
        if(col[cols[arr[i]]]==mat.size()){
            return i;
        }
       }
       return 0;
    }
};