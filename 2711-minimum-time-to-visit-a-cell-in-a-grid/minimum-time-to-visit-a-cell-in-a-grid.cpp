class Solution {
    public:
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    void push(vector<vector<int>>&grid, int i, int j, int curr){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]!=-1){
            if(grid[i][j]<=curr+1) pq.push({curr+1,{i, j}});
            else {
                int temp=(grid[i][j]-curr-1)%2==0?grid[i][j]:grid[i][j]+1;
                pq.push({temp, {i,j}});
            }
        }
    }
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 and grid[1][0]>1) return -1;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int curr=pq.top().first;
            pair<int,int> node =pq.top().second;
            int i=node.first, j=node.second;
            pq.pop();
            if(grid[i][j]==-1) continue;
            grid[i][j]=-1;
            if(i==grid.size()-1 && j==grid[0].size()-1) return curr;
            push(grid, i-1, j, curr); push(grid, i+1, j, curr);
            push(grid, i, j-1, curr); push(grid, i,j+1, curr);
        }
        return -1;
    }
};