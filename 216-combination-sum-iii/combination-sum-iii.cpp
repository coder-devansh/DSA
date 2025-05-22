class Solution {
public:
vector<vector<int>>result;
void find(int i,int target,int k,vector<int>&ans,int  sum){
    if(target<0){
        return;
    }
    if(k==0){
        if(target==0){
            result.push_back(ans);
        }
        return;
    }
    for(int j=i;j<=9;j++){
        ans.push_back(j);
        find(j+1,target-j,k-1,ans,sum);
        ans.pop_back();
        
    }
    

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vis;
        find(1,n,k,vis,0);
        return result;
        
    }
};