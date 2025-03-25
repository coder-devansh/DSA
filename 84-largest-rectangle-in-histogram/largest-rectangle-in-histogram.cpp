class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>ans;
        stack<int>st;
        int n=heights.size();
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(n);
                st.push(i);
            }else{
                ans.push_back(st.top());
                st.push(i);

            }
        }
        while(!st.empty()) st.pop();
        reverse(ans.begin(),ans.end());
        vector<int>prev_small;
       
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                prev_small.push_back(-1);
                st.push(i);
            }else{
                prev_small.push_back(st.top());
                st.push(i);

            }
        }
        int maxi=INT_MIN;
       for(int i=0;i<heights.size();i++){
        int res=(ans[i]-prev_small[i]-1)*heights[i];
        maxi=max(maxi,res);
       }
       return maxi;
        
    }
};