class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        bool found=true;
        for(int i=1;i<s.size();i++){
            if(abs(s[i]-s[i-1])>2)found=false;
        }
        return found;
        
    }
};