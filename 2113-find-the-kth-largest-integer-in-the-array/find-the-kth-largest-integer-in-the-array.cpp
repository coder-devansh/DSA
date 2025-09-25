struct compare {
    bool operator()(const string &a, const string &b) {
        if (a.size() == b.size())
            return a > b;  // smaller comes first
        return a.size() > b.size(); // shorter comes first
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,compare>pq;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k)pq.pop();
            
            
        }
        return pq.top();
        
    }
};