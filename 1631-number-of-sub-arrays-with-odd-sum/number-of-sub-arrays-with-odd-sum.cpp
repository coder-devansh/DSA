class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum=0;
        int even_count=1;
        int odd_count=0;
        int mod=(int)1e9+7;
        int odd_sub=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                 odd_sub=(odd_sub+odd_count)%mod;
                even_count++;
            }
            else if(sum%2!=0){
                odd_sub=(odd_sub+even_count)%mod;
                odd_count++;

            }
        }
        return odd_sub;
        
    }
};