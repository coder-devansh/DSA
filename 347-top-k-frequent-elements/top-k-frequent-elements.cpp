class Solution {
public:

struct compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first == b.first) 
            return a.second < b.second;
        return a.first > b.first;     
    }
};
    vector<int> topKFrequent(vector<int>& words, int k) {
        map<int,int>mp;
        set<pair<int,int>,compare>pq;
        for(int i=0;i<words.size();i++){
            pq.erase({mp[words[i]],words[i]});
            mp[words[i]]++;
            pq.insert({mp[words[i]],words[i]});
        }
         int count=0;
         vector<int>ans;
        for(auto it:pq){
            if(count==k)break;
            ans.push_back(it.second);
            count++;
        }
        return ans;
       
        

        
    }
};