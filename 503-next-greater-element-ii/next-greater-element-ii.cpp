class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>copy(nums.size()+nums.size(),0);
        int j=0;
        for(int i=0;i<copy.size();i++){
            if(j==nums.size()){
                j=0;
            }
            copy[i]=nums[j];
            j++;
        }
       
        
        vector<int>neg(nums.size(),0);
        for(int i=copy.size()-1;i>=0;i--){
            while(!st.empty() && copy[i]>=copy[st.top()])
            {
                st.pop();

            }
            if(st.empty()){
                if(i>=0 && i<nums.size()) neg[i]=-1;
            }else{
                if(i>=0 && i<nums.size())  neg[i]=copy[st.top()];
               
            }
            st.push(i);

            
        }
        
        return neg;
        
    }
};