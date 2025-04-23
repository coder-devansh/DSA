class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++)
        {
            int x=asteroids[i];
            bool flag=1;
            while(!st.empty() && st.top()>0 && x<0){
                int first=st.top();
                int second=abs(x);
                st.pop();
                if(first>second){
                    x=first;
                }
                else if(first==second){
                    flag=0;
                    break;
                }
                
            }
            if(flag)
            {
                st.push(x);

            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};