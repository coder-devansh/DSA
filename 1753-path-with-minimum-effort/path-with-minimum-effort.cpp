class Solution {
public:
int row[4]={-1,0,1,0};
int col[4]={0,-1,0,1};

bool canPossible(vector<vector<int>>&grid,int mid){
    vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),1e9));
    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
    queue<pair<int,int>>q;
    int n=grid.size()-1;
    int m=grid[0].size()-1;
    q.push({0,0});
    vis[0][0]=1;
    dist[0][0]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int i=it.first;
        int j=it.second;
        for(int k=0;k<4;k++){
            int new_row=i+row[k];
            int new_col=j+col[k];
            if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size() && !vis[new_row][new_col]){
                if(abs(grid[i][j]-grid[new_row][new_col])<=mid){
                    q.push({new_row,new_col});
                    dist[new_row][new_col]=1;
                    vis[new_row][new_col]=1;
                }

            }
        }
    }
    return dist[n][m]==1;
}
    int minimumEffortPath(vector<vector<int>>& grid) {
        int max_value=0;
        int min_value=INT_MAX;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                max_value=max(max_value,grid[i][j]);
                min_value=min(min_value,grid[i][j]);
            }
        }
        int low=0;
        int high=abs(max_value-min_value);
        int min_result=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPossible(grid,mid)){
                min_result=min(min_result,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return min_result;
    }
        
};