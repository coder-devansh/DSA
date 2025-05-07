class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int time=it.first;
            int new_row=it.second.first;
            int new_col=it.second.second;
            for(int i=0;i<4;i++){
                int row=new_row+r[i];
                int col=new_col+c[i];
                if(row>=0 && col>=0 && row<n && col<m){
                    int diff=max(time,moveTime[row][col])+1;
                    if(diff<dist[row][col]){
                        dist[row][col]=diff;
                        q.push({diff,{row,col}});
                    }
                
                
               
            }
            }
            
            

        }
        return dist[n-1][m-1];



        
    }
};