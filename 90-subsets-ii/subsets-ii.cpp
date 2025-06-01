class Solution {
public:
set<vector<int>>st;
vector<vector<int>>result;
void find_subset(int i,vector<int>nums,vector<int>arr){
    if(i==nums.size()){
        if(st.find(arr)==st.end()){
            st.insert(arr);
              result.push_back(arr);

        }
        return;
      

    }
    arr.push_back(nums[i]);
    find_subset(i+1,nums,arr);
    arr.pop_back();
    find_subset(i+1,nums,arr);
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        find_subset(0,nums,arr);
        return result;
        
    }
};