class Solution {
public:
// int getDistance(vector<vector<int>>&grid,int i,int j){
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
//     q.push({0,{i,j}});
    

//     }
//     return 0;
// }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;

                }else
                {
                    vis[i][j]=0;
                }
            }
        }

    int rows[4]={-1,0,1,0};
    int cols[4]={0,-1,0,1};
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int time=it.first;
        int row=it.second.first;
        int col=it.second.second;
        dist[row][col]=time;
        for(int i=0;i<4;i++){
            int new_row=row+rows[i];
            int new_col=col+cols[i];
            if(new_row>=0 && new_row<mat.size() && new_col>=0 && new_col<mat[0].size() && vis[new_row][new_col]==0){
                vis[new_row][new_col]=1;
               
                    q.push({time+1,{new_row,new_col}});
                

        }

        }
    }

        
        return dist;
        
    }
};