class Solution {
public:
    string removeKdigits(string nums, int k) {
        k=nums.size()-k;
         stack<int>st;
      int n=nums.size();
      for(int i=0;i<nums.size();i++){
        int val=nums[i];
        while(!st.empty() && st.top()>val  && (st.size()-1+(n-i))>=k){
            st.pop();
        }
        if(st.size()<k){
            st.push(val);

        }
        
      }
      string ans="";
      while(ans.size()!=k && !st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
      string result="";
      int i=0;
      reverse(ans.begin(),ans.end());
      for( i=0;i<ans.size();i++){
        if(ans[i]!='0'){
            break;
        }
    
      }
      for(int j=i;j<ans.size();j++){
        result+=ans[j];

      }
      if(result.size()==0){
        return "0";
      }
      return result;

        
    }
};