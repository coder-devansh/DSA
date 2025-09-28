class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int t=0;
        int f=0;
        int right=0;
        int left=0;
        int maxi=INT_MIN;
        while(right<s.size()){
            if(s[right]=='T'){
                t++;
            }else{
                f++;
            }
            while(t>k && f>k){
                if(s[left]=='T'){
                    t--;
                }else{
                    f--;
                }
                left++;
            }
            if(t<=k | f<=k){
                maxi=max(maxi,right-left+1);
            }
            right++;
        }
        return maxi;
        
    }
};