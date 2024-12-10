class Solution {
public:
bool uniquechar(string s){
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[0]) return false;
    }
    return true;
}
bool canmake(int len,string s){
    map<string,int>mp;
    for(int i=0;i<=s.size()-len;i++){
        if(uniquechar(s.substr(i,len))){
            mp[s.substr(i,len)]++;
        }
    }
    for(auto it:mp){
        if(mp[it.first]>=3){
            return true;
        }
    }
    return false;
}
    int maximumLength(string s) {
        int st=1;
        int e=s.size();
        int ans=-1;
        while(st<=e){
            int mid=(st+e)/2;
            if(canmake(mid,s)){
                st=mid+1;
                ans=mid;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};