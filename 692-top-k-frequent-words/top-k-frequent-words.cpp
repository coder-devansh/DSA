class Solution {
public:

struct compare {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) 
            return a.second < b.second;
        return a.first > b.first;     
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        set<pair<int,string>,compare>pq;
        for(int i=0;i<words.size();i++){
            
            mp[words[i]]++;
        }
        for(auto it:mp){
            pq.insert({it.second,it.first});
        }
         int count=0;
         vector<string>ans;
        for(auto it:pq){
            if(count==k)break;
            ans.push_back(it.second);
            count++;
        }
        return ans;
    }
};