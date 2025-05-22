class Solution {
public:
vector<vector<int>>result;
void find(int i,int n,int k,vector<int>ans){
    if(k==0){
        result.push_back(ans);
        return;
    }
    for(int j=i;j<=n;j++){
        ans.push_back(j);
        find(j+1,n,k-1,ans);
        ans.pop_back();
    }


}
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        find(1,n,k,ans);
        return result;
        
    }
};