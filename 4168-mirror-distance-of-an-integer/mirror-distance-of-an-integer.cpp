class Solution {
public:
    int mirrorDistance(int n) {
        string str=to_string(n);
        long long val1=stoll(str);
        reverse(str.begin(),str.end());
        long long val2=stoll(str);
        return abs(val1-val2);
        
    }
};