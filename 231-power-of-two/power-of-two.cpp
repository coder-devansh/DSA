class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0 ){
            return false;

        }
        long long val=(long long)n;
        long long min_val=(long long )n-1;
        if((val & min_val)==0)return true;
        return false;
        
    }
};