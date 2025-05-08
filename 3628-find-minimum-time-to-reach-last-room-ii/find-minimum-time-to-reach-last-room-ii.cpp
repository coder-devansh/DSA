class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>>dist(n+1,vector<int>(m+1,INT_MAX));
         priority_queue<
        pair<pair<int, int>, pair<int, int>>,
        vector<pair<pair<int, int>, pair<int, int>>>,
        greater<>
    > q;

        q.push({{0,1},{0,0}});
        dist[0][0]=0;
       
        int r[4]={-1,0,1,0};
        int c[4]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int time=it.first.first;
            int index=it.first.second;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=0;i<4;i++){
                int new_row=row+r[i];
                int new_col=col+c[i];
                if(new_row>=0 && new_col>=0 && new_row<n && new_col<m)
                {
                    int diff=0;
                    if(index%2==0){
                          diff=max(time,moveTime[new_row][new_col])+2;

                    }else{
                        diff=max(time,moveTime[new_row][new_col])+1;
                    }
                  

                    
                    
                    if(diff<dist[new_row][new_col]){
                        
                       
                        dist[new_row][new_col]=diff;
                      
                        q.push({{diff,index+1},{new_row,new_col}});
                    }
                    
                   
                   
                }
                 
            }
        }
        return dist[n-1][m-1];

        
    }
};