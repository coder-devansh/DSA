class Solution {
public:
vector<vector<int>>vis;
long long sum;
int r[4]={-1,0,1,0};
int c[4]={0,-1,0,1};
void bfs(int i,int j,vector<vector<int>>&grid){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        vis[row][col]=1;
        for(int x=0;x<4;x++){
            int new_r=row+r[x];
            int new_c=col+c[x];
            if(new_r>=0 && new_r<grid.size() && new_c>=0 && new_c<grid[0].size() &&  !vis[new_r][new_c] && grid[new_r][new_c]>0){
                vis[new_r][new_c]=1;
                sum+=grid[new_r][new_c];
                q.push({new_r,new_c});
            }
        }
    }
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        vis.resize(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    sum=grid[i][j];
                    bfs(i,j,grid);
                    if((sum%k)==0)count++;
                }
            }
        }
        return count;

        
    }
};