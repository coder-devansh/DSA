class Solution {
public:
    long long flowerGame(int n, int m) {
         long long count_odd=0;
         long long  count_even=0;
         for(int i=1;i<=n;i++){
            if(i%2!=0){
                count_odd++;
            }else{
                count_even++;
            }
         }
         long long count_odd1=0;
         long long count_even1=0;
         for(int i=1;i<=m;i++){
            if(i%2!=0){
                count_odd1++;
            }else{
                count_even1++;
            }
         }
         return ((count_even*count_odd1)+(count_even1*count_odd));
        
    }
};