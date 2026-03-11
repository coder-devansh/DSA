#define ll long long
class Solution {
public:
// trick is that number of continuos one is less than limit and the number of zontinuos zero is less than limit
// so we make the subarray where continous number of zero and continuos number of zero is less than limit;
vector<vector<vector<ll>>>dp;
const int mod=(int)1e9+7;
ll solve(int zero,int one,int limit,bool lastOne)
{
    if(zero==0 && one==0)return 1;
    if(dp[one][zero][lastOne]!=-1)return dp[one][zero][lastOne];
    ll result=0;
    if(lastOne==true){
        for(int i=1;i<=min(limit,zero);i++){
            result=(result+solve(zero-i,one,limit,false))%mod;
        }
    }else{
        for(int i=1;i<=min(limit,one);i++){
            result=(result+solve(zero,one-i,limit,true))%mod;
        }
    }
    return dp[one][zero][lastOne]=result;
}


    int numberOfStableArrays(int zero, int one, int limit) {
        dp.resize(one+1,vector<vector<ll>>(zero+1,vector<ll>(2,-1)));
        ll ans=(ll)solve(zero,one,limit,false);
       return (ans+(ll)solve(zero,one,limit,true))%mod;

        
    }
};