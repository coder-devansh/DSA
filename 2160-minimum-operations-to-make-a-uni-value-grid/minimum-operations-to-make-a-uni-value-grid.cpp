class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       vector<int>ans;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            ans.push_back(grid[i][j]);
        }
       }
       sort(ans.begin(),ans.end());
       map<int,int>mp;
       for(auto it:ans){
        mp[it%x]++;
       }
       if(mp.size()>1) return -1;
       int l=0;
       int r=ans.size()-1;
       int mid=ans.size()/2;
       int change_val=ans[mid];
       int cnt=0;
       for(int i=0;i<ans.size();i++){
        cnt+=(abs(change_val-ans[i])/x);

       }
       return cnt;
       

    }
};