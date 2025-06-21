class Solution {
public:
int  findPrime(int n){
    vector<int>isPrime(n,true);
    isPrime[1]=false;
    isPrime[0]=false;
    for(int i=2;i*i<n;i++)
    {
        if(isPrime[i]){
             for(int j=i*i;j<n;j+=i){
                isPrime[j]=false;

        }

        }
       
    }
    int count=0;
    for(int i=1;i<n;i++){
        count+=(isPrime[i]==true)?1:0;
    }
    return count;
}
    int countPrimes(int n) {
        if(n==0 || n==1)return 0;
       return findPrime(n);
        
    }
};