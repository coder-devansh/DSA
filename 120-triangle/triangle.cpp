class Solution {
public:
int find_sum(int i,int j,vector<vector<int>>&triangle){
    if(i==triangle.size()-1 && j<triangle[i].size()){
        return triangle[i][j];
    }
    if(i<0 || j<0 || i>=triangle.size() || j>=triangle[i].size()){
        return INT_MAX;
    }
    int left=find_sum(i+1,j,triangle);
    int right=find_sum(i+1,j+1,triangle);

    return min(left,right)+triangle[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<triangle[n-1].size();i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
        // return find_sum(0,0,triangle);   recursive view
        

        
    }
};