class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s="";
        int count=0;
        while(s.find(b)==string::npos && s.size()<=1e4){
            s+=a;
            count++;
        }
        if(s.find(b)==string::npos){
            return -1;
        }
        return count;
        
    }
};