class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

    int width;
    int maxi=INT_MIN;
    stack<int>st;
    for(int i=0;i<=heights.size();i++){
        while(!st.empty() && (i==heights.size()|| heights[st.top()]>=heights[i])){
            int height=heights[st.top()];
            st.pop();
            if(st.empty()) width=i;
            else width=i-st.top()-1;
            maxi=max(maxi,width*height);
        }
        st.push(i);
    }
    return maxi;
    }
};