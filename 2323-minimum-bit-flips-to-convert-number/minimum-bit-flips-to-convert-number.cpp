class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        cnt+=(start ^ goal);
        int ans=0;
        while(cnt>0)
        {
           cnt&=(cnt-1);
           ans++;

        }
        return ans;
        
    }
};