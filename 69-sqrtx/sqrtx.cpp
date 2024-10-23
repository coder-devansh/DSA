class Solution {
public:
    int mySqrt(int n) {

          int low=0;
         int ans=0;
         int high=n;
        while(low<=high){
     double  mid=(low+high)/2;
        if((mid*mid)==n){
            return mid;
        }
        else if((mid*mid)>n){
            high=mid-1;
        }
        else{
            ans=mid;
            low=mid+1;
        }
        }
        return ans;
        
    }
};