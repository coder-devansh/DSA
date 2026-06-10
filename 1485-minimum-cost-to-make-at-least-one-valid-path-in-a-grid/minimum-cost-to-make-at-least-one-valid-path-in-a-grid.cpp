struct compare{
    bool operator()(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
        return a.first > b.first;
    }
};
int dir[5]={0,0,0,1,-1};
int dic[5]={0,1,-1,0,0};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<long long>>best(grid.size(),vector<long long>(grid[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        best[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int cost=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1)return cost;
            if(best[row][col]<cost)continue;
            int new_r=row+dir[grid[row][col]];
            int new_c=col+dic[grid[row][col]];
            if(new_r>=0 && new_c>=0 && new_r<n && new_c<m){
                if(cost < best[new_r][new_c]){
    best[new_r][new_c] = cost;
    pq.push({cost,{new_r,new_c}});
}
            }
            for(int k=1;k<=4;k++){
                if(grid[row][col]!=k){
                    int r=row+dir[k];
                    int c=col+dic[k];
                    if(r>=0 && c>=0 && r<n && c<m){
                       if(cost + 1 < best[r][c]){
    best[r][c] = cost + 1;
    pq.push({best[r][c], {r,c}});
}
                    }
                }
            }
        }
        return -1;

        
    }
};