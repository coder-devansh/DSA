class Solution {
public:
vector<vector<int>>result;
set<vector<int>>st;
void find_combo(int i,vector<int>&candidates,int target,vector<int>&nums){
    if(target==0){
        if(st.find(nums)==st.end()){
            st.insert(nums);
             result.push_back(nums);

        }
       
        return;
    }
    if(target<0){
        return;
    }
    for(int k=i;k<candidates.size();k++){
        if(k>i && candidates[k]==candidates[k-1])continue;
        if(candidates[i]>target)break;
        nums.push_back(candidates[k]);
        find_combo(k+1,candidates,target-candidates[k],nums);
        nums.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>nums;
        sort(candidates.begin(),candidates.end());
        find_combo(0,candidates,target,nums);
        return result;

        
    }
};