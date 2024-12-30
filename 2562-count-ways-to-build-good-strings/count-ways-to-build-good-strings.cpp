class Solution {
public:
int mod=1e9+7;
vector<long long >dp;
int count(int i,int zero,int one){
    if(i==0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

    long long taken=(count(i-one,zero,one))%mod;
    long long  nottaken=(count(i-zero,zero,one))%mod;
    return dp[i]=(taken+nottaken)%mod;;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        int sum=0;
        dp.resize(high+1,-1);
        for(int i=low;i<=high;i++){
           sum=(sum+count(i,zero,one))%mod;
        }
        return sum%mod;

        
    }
};