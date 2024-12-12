class Solution {
public:
long long sqrts(long long  value){
    long long  low=1;
    long long  high=value/2;
    while(low<=high){
        long long  mid=(low+high)/2;
        if((mid*mid)==value){
            cout<<mid;
            return mid;
        }else if((mid*mid)>value){
            high=mid-1;
            
        }else{
            low=mid+1;
        }
    }
    cout<<low;
    return low;
}
    long long pickGifts(vector<int>& gifts, int k) {
        
        sort(gifts.begin(),gifts.end());
        long long  total=0;
        int t=0;
       
       
     
        for(int i=1;i<=k;i++){
           int  max_gift_idx = max_element(gifts.begin(), gifts.end()) - gifts.begin();
        
        // Update the number of gifts in the selected pile
        gifts[max_gift_idx] = floor(sqrt(gifts[max_gift_idx]));
           }
           long long ans=0;
           int mod=10000000007;
     for(auto it:gifts){
        ans+=it;
        

     }
       return ans;
        
    }
};