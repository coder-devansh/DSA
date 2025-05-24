class Solution {
public:
vector<vector<int>>result;
void find(int i,vector<int>&candidates,int target,vector<int>&ans){
    if(target==0){
        result.push_back(ans);
        
    }
    if(target<0){
        return;
    }

    for(int j=i;j<candidates.size();j++){
        ans.push_back(candidates[j]);
        find(j,candidates,target-candidates[j],ans);
        ans.pop_back();

    }
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        find(0,candidates,target,ans);
        return result;
        
    }
};