class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        long long value=pow(3,19);
        if(value % n==0)return true;
        return false;
        
    }
};