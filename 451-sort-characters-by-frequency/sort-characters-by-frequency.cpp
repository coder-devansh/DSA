class Solution {
public:
static bool custom(const pair<char,int>&a,const pair<char,int>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
    string frequencySort(string s) {
        vector<pair<char,int>>vec;
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;

        }
        for(auto it:mp){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),custom);
        string ans="";
        for(auto it:vec){
            for(int i=0;i<it.second;i++){
                ans+=it.first;

            }
        }
        return ans;

        
    }
};