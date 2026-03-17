class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>prefix(matrix.size(),vector<int>(matrix[0].size(),0));
        int m=matrix[0].size();
        int n=matrix.size();
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]==1)cnt++;
                else cnt =0;
                prefix[i][j]=cnt;
            }
        }
        int maxi=0;
    for(int i=0;i<n;i++)sort(prefix[i].begin(),prefix[i].end());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int height=prefix[i][j];
            maxi=max(maxi,height*(m-j));
        }
    }
    return maxi;
        
    }
};