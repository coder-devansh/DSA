class Solution {
public:
 int mod=1000000007;
 long long power(long long  base,long long  n){
   
    long long res=1;
    while(n){
        if(n%2==1){
            res=(res*base)%mod;
        }
        if(n==1) break;
        base=(base*base)%mod;
        n/=2;
    }
    return (res)%mod;
 }
    int countGoodNumbers(long long n) {
        long long count=0;
        int even_count=5;
        int odd_count=5;
        int prime_count=4;
        long long  even_index=(n+1)/2;
        long long  odd_index=n/2;
        if(n==1){
            return 5;
        }
       
       
      count=((power(4,odd_index))%mod*(power(5,even_index))%mod)%mod;
        return (count)%mod;
        
    }
};