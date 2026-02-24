class Solution {
public:
int r[4]={-1,0,1,0};
int c[4]={0,-1,0,1};
bool canbe(int mid,vector<vector<int>>&grid)
{
    queue<pair<int,int>>q;
    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
    q.push({0,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        if(row==grid.size()-1 && col==grid[0].size()-1)return true;
        for(int i=0;i<4;i++){
            int new_row=row+r[i];
            int new_col=col+c[i];
            if(new_row>=0 && new_col>=0 && new_row<grid.size() && new_col<grid[0].size() && !vis[new_row][new_col]){
                if(grid[row][col]<=mid  && grid[new_row][new_col]<=mid){
                    vis[new_row][new_col]=1;
                    q.push({new_row,new_col});

                }
                
            }
        }
    }
    return false;

}
    int swimInWater(vector<vector<int>>& grid) {
        int low=0;
        int maxi=0;
        for(auto it:grid){
            for(auto ele:it){
                maxi=max(maxi,ele);
            }
        }
        int high=maxi;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canbe(mid,grid)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
       
    }
};