#define ll long long
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        ll ans=0;
        ll i=0;
        while(n){
            if(!(n & 1))ans+=pow(2,i);
            n=n>>1;
            i++;

        }
       return ans;
        
      

        
    }
};