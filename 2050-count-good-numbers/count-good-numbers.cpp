class Solution {
public:
int fun(long long x,long long n)
{
    const int mod=pow(10,9)+7;
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        return fun((x*x)%mod,n/2);
    }
    else{
        return (x*fun(x,n-1)%mod);
    }



}
    int countGoodNumbers(long long n) {
       long long  even=n/2+n%2;
       long long  odd=n/2;
       long long  num=fun(5,even);
       const int mod=pow(10,9)+7;
      long long num1=fun(4,odd);
       long long ans=((num*num1)%mod);
       return ans;
    }
};