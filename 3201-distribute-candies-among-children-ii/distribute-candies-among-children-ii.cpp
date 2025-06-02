class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int mini=max(0,n-2*limit);
        int maxi=min(limit,n);
        long long  ways=0;
        for(int i=mini;i<=maxi;i++){
            int N=n-i;
            int ch1_min=max(0,N-limit);
            int ch2_max=min(N,limit);
            ways+=ch2_max-ch1_min+1;
        }
        return ways;
        
    }
};