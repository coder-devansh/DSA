class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>prefix(5000001,0);
        for(auto&it:shifts){
            int start=it[0];
            int end=it[1];
            int dir=it[2];
           dir=(dir==0)?-1:1;
            prefix[start]+=dir;
            if(end+1<s.size()){
                prefix[end+1]-=dir;
            }
           
            }
            for(int i=1;i<s.size();i++){
                prefix[i]+=prefix[i-1];
               
            }
            int n=s.size();
             for (int i = 0; i < n; i++) {
        int shift = prefix[i];
        int newChar = (s[i] - 'a' + shift) % 26; 
        if (newChar < 0) {
            newChar += 26;
        }
        s[i] = 'a' + newChar; 
    }

            
           
        
        return s;
        
    }
};