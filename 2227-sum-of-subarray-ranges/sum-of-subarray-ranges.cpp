class Solution {
public:
long long subarray_maximum(vector<int>&nums){
    int n=nums.size();
    vector<int>nse(n+1);
    vector<int>psee(n+1);
    stack<int>st;
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
        }
        psee[i]=st.empty()?-1:st.top();
        st.push(i);

    }
    stack<int>mp;
    for(int i=nums.size()-1;i>=0;i--){
        while(!mp.empty() && nums[mp.top()]<=nums[i]){
            mp.pop();
        }
        nse[i]=mp.empty()?n:mp.top();
        mp.push(i);
    }
    long long sum=0;
    const int mod=(int)1e9+7;
    for(int i=0;i<nums.size();i++)
    {
        long long product=((i-psee[i])*(nse[i]-i))%mod;
        product=(product*nums[i]);
        sum=(sum+product);

    }
    return sum;
}
long long subarray_minimum(vector<int>&nums){
    int n=nums.size();
    vector<int>nse(n+1);
    vector<int>psee(n+1);
    stack<int>st;
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            st.pop();
        }
        psee[i]=st.empty()?-1:st.top();
        st.push(i);

    }
    stack<int>mp;
    for(int i=nums.size()-1;i>=0;i--){
        while(!mp.empty() && nums[mp.top()]>=nums[i]){
            mp.pop();
        }
        nse[i]=mp.empty()?n:mp.top();
        mp.push(i);
    }
    long long sum=0;
    const int mod=(int)1e9+7;
    for(int i=0;i<nums.size();i++)
    {
        long long product=((i-psee[i])*(nse[i]-i))%mod;
        product=(product*nums[i]);
        sum=(sum+product);

    }
    return sum;
}
    long long subArrayRanges(vector<int>& nums) {
       return  subarray_maximum(nums)-subarray_minimum(nums);
        
    }
};