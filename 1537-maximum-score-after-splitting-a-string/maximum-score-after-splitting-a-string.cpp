class Solution {
public:
    int maxScore(string s) {
        vector<int>prefix(s.size(),0);
        int sum=0;

        for(int i=s.size()-1;i>=0;i--){
            sum+=s[i]-'0';
            prefix[i]=sum;

        }
        sum=0;
        int maxi=0;

        
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                sum++;
            }
            maxi=max(maxi,sum+prefix[i+1]);
        }
        return maxi;
        
    }
};