class Solution {
public:
bool nonPrime(long long ele1,long long ele2){
    return gcd(ele1,ele2)>1;
}

long long gcd(long long a,long long b){
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a,long long b){
    return (a*b)/gcd(a,b);
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long>st;
         vector<int>ans;
        for(int i=0;i<nums.size();i++){
            long long curr=nums[i];
           while(!st.empty() && gcd(st.top(),curr)>1){
            curr=lcm(st.top(),curr);
            st.pop();

           }
           st.push(curr);
           
            

        }
       
        while(!st.empty())
        {
            long long val=st.top();
            ans.push_back(val);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};