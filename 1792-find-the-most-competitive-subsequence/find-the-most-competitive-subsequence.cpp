class Solution {
public:
vector<vector<int>>result;
void find(int i,vector<int>&nums,int k,vector<int>ans){
    if(k==0){
        result.push_back(ans);
        return;
    }
    if(i==nums.size()){
        return;
    }
    if(ans.size()==0 || (ans.size()>=1 && ans[ans.size()-1]<=nums[i])){
    ans.push_back(nums[i]);
    find(i+1,nums,k-1,ans);
    ans.pop_back();

    }
    
    find(i+1,nums,k,ans);
}
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      stack<int>st;
      int n=nums.size();
      for(int i=0;i<nums.size();i++){
        while(!st.empty() && st.top()>nums[i]  && (st.size()-1+(n-i))>=k){
            st.pop();
        }
        if(st.size()<k){
            st.push(nums[i]);

        }
        
      }
      vector<int>ans;
      while(ans.size()!=k && !st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;

        
    }
};