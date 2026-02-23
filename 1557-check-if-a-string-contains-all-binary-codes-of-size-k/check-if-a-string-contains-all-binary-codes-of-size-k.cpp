class Solution {
public:
set<string>match;
    bool hasAllCodes(string s, int k) {
        if(s.size()<=k)return false;
        set<string>st;
        string str="";
        int right=0;
        int left=0;
        while(right<s.size()){
            str+=s[right];
            if((right-left+1)==k){
                st.insert(str);
                str.erase(0,1);
                left++;
            }
            right++;
        }
    
         
       if(st.size()==pow(2,k))return true;
       return false;
        
    }
};