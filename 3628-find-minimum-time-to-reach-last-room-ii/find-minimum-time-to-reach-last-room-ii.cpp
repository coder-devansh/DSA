class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        int vis[n][m];
        int turn=0;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
      
        
        vector<pair<int,int>>adj[n];
       priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>q; 
        
        int min_time=INT_MAX;
        q.push({{0,2},{0,0}});
        vis[0][0]=1;
        dis[0][0]=0;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int x=it.second.first;
            int y=it.second.second;
            int time=it.first.first;
            int len=it.first.second;
            if(x==n-1 && y==m-1)
            {
                return time;
            }
            
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int finalx=x+row[i];
                int finaly=y+col[i];
              if(finalx>=0 && finalx<moveTime.size() && finaly>=0 && finaly<moveTime[0].size())
              {
                int diff=0;
                if((len==2)){
                    
    
                      diff=max(time+1,moveTime[finalx][finaly]+1);
                      if(diff<dis[finalx][finaly])
                {
                    
                    dis[finalx][finaly]=diff;
                    q.push({{diff,0},{finalx,finaly}});
                }

                }
                else{
                    
                       diff=max(time+2,moveTime[finalx][finaly]+2);
                 if(diff<dis[finalx][finaly])
                {
                    turn++;
                    dis[finalx][finaly]=diff;
                    q.push({{diff,2},{finalx,finaly}});
                }

                }
              
               
                
              }


            }




        }
       
        
        
        return -1;
    }
};