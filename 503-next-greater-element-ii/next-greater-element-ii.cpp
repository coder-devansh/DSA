class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size(),0);
        vector<int>nums(arr);
        for(int i=0;i<arr.size();i++){
            nums.push_back(arr[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();

            }
            if(st.empty() && i<arr.size()){
                ans[i]=-1;
            }else{
                if(i<arr.size()){
                    ans[i]=st.top();

                }
                
            }
            st.push(nums[i]);


        
        }
        return ans;
        

    }
};