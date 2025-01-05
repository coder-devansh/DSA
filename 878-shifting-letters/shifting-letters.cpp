class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long >prefix(s.size()+1,0);
        long long  sum=0;
        for(int i=s.size()-1;i>=0;i--){
            sum+=shifts[i];
            prefix[i]=sum;

        }
        for(int i=0;i<s.size();i++){
            int newchar=(s[i]-'a'+prefix[i])%26;
            if(newchar<0){
                newchar+=26;

            }
            s[i]='a'+newchar;
            
        }
        return s;
        
    }
};