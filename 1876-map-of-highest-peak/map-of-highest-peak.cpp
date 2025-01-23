class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>>q;
        vector<vector<int>>height(isWater.size(),vector<int>(isWater[0].size(),-1e9));
                vector<vector<int>>vis(isWater.size(),vector<int>(isWater[0].size(),0));

        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1){
                    vis[i][j]=1;
                    height[i][j]=0;
                    
                    q.push({i,j});


                }

            }
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=0;i<4;i++){
                int new_r=row+dr[i];
                int new_c=col+dc[i];
                if(new_r>=0 && new_r<isWater.size() && new_c>=0 && new_c<isWater[0].size() ){
                    if((height[row][col]+1)>height[new_r][new_c] && !vis[new_r][new_c])
                    {
                        height[new_r][new_c]=height[row][col]+1;
                        vis[new_r][new_c]=1;
                        q.push({new_r,new_c});

                    }

                }
            }
        


        }
        return height;
    }
};