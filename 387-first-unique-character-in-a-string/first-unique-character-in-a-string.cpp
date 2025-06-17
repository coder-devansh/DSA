class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        map<char,int>index;;
        int i=0;
        for(auto it:s){
            index[it]=i;
            i++;
            mp[it]++;
        }
        int mini=INT_MAX;
        for(auto it:mp){
            if(it.second==1) mini=min(mini,index[it.first]);
        }
        return mini==INT_MAX?-1:mini;
    
        
    }
};