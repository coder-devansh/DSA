class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       
       int vis[n][m];
     
      
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                   
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int t=0;
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int tm=it.second;
            t=max(tm,t);
            q.pop();
            
          int r[]={-1,0,1,0};
          int c[]={0,1,0,-1};
           int turn=0;
          for(int i=0;i<4;i++){
            int rows=row+r[i];
            int column=col+c[i];
           
            if(rows>=0 && rows<grid.size() && column>=0 && column<grid[0].size() && vis[rows][column]==0 && vis[rows][column]!=2 && grid[rows][column]==1)
            {
                vis[rows][column]=2;
                q.push({{rows,column},tm+1});
                
            }

          }
         
         
          
            

        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return t;
        
    }
};