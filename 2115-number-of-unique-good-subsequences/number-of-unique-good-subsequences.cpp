class Solution {
public:
int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
   int dp1=0;
   int dp0=0;
   bool has_zero=false;
   for(int i=0;i<binary.size();i++){
    char ch=binary[i];
    if(ch=='1')
    {
        dp1=(dp1+dp0+1)%mod;
    }else{
        dp0=(dp0+dp1)%mod;
        has_zero=true;
    }
   }
   if(has_zero==false){
    return binary.size();
   }
   return (dp1+dp0+(has_zero?1:0))%mod;
    //   bool has_zero=false;
    //    for(int i=1;i<=binary.size();i++){
    //     if(binary[i-1]=='1'){
    //         dp1[i]=dp1[i-1]+dp0[i-1]+1;
    //     }else{
    //         dp0[i]=dp0[i-1]+dp1[i-1];
    //         has_zero=true;
    //     }
    //    }
    //     if(has_zero==false){
    //         return binary.size();
    //     }
    //     for(int i=0;i<=binary.size();i++){
    //        cout<<dp1[i]<<"";
            
    //     }
    //     cout<<endl;
    //     for(int i=0;i<=binary.size();i++){
    //         cout<<dp0[i]<<" ";
    //     }
    //     return (dp1[binary.size()]+dp0[binary.size()]+has_zero);
        
    }
};