class Solution {
public:

struct compare {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) 
            return a.second < b.second; // tie-break by string
        return a.first > b.first;       // sort by int
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        set<pair<int,string>,compare>pq;
        for(int i=0;i<words.size();i++){
            pq.erase({mp[words[i]],words[i]});
            mp[words[i]]++;
           pq.insert({mp[words[i]],words[i]});
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