#define ll long long
int dir[8]={-1,-1,0,1,1,1,0,-1};
int dic[8]={0,1,1,1,0,-1,-1,-1};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<ll>>dist(n,vector<ll>(m+1,INT_MAX));
        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0][0]=1;
        if(grid[0][0]==1)return -1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            if(row==n-1 && col==m-1)continue;
            for(int i=0;i<8;i++){
                int new_r=row+dir[i];
                int new_c=col+dic[i];
                if(new_r>=0 && new_c>=0 && new_r<n && new_c<m && grid[new_r][new_c]==0){
                    if(dist[row][col]+1<dist[new_r][new_c]){
                        dist[new_r][new_c]=dist[row][col]+1;
                        q.push({new_r,new_c});

                    }
                }
            }

        }
        if(dist[n-1][m-1]>=INT_MAX)return -1;
        return dist[n-1][m-1];


        
    }
};