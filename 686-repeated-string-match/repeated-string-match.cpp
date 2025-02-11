class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        map<char,int>mp;
        map<char,int>first;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(mp[b[i]]==0){
                return -1;
            }
        }
        int count=0;
        string s="";
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