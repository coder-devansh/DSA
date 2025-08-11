class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>power;
        vector<int>ans;
        if((n & n-1)==0){
            power.push_back(n);
            for(auto it:queries){
                ans.push_back(n);


            }
            return ans;
        }

    long long sum=0;
     int mod=(int)1e9+7;
    unsigned int res = 1;
    long long val=n;
    while (n >>= 1) {
        res <<= 1;
    }
    for(int i=res;i>=1;i/=2){
       if(sum+i>val){
        continue;
       }
       sum+=i;
       if(sum==val){
         power.push_back(i % mod);
         break;

       }
       power.push_back(i % mod);
    }
   
    reverse(power.begin(),power.end());
    for(auto it:queries){
      int i=it[0];
      int j=it[1];
      long long product=1;
      for(int k=i;k<=j;k++){
        product=(product * power[k]) % mod;
      }
      ans.push_back((int)(product % mod));
    }

   
        return ans;

     
        
    }
};