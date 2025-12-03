class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse(arr.size()+1);
        vector<int>psee(arr.size()+1);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);


        }
        stack<int>mp;
        for(int i=arr.size()-1;i>=0;i--){
            while(!mp.empty() && arr[mp.top()]>=arr[i]){
                mp.pop();
            }
            nse[i]=mp.empty()?arr.size():mp.top();
            mp.push(i);

        }
        const int mod=(int)1e9+7;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
           long long product=((nse[i]-i)*(i-psee[i]))%mod;
           product=(product*arr[i])%mod;
           sum=(sum+product)%mod;


        }
        return sum;
        
    }
};