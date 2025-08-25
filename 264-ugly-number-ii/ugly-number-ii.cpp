class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>primes={2,3,5};
        set<int>visited;
        priority_queue<long long ,vector<long long>,greater<long long >>pq;
        pq.push(1);
        visited.insert(1);
   long long curr=0;
        for(int i=0;i<n;i++){
             curr=pq.top();
            pq.pop();

            for(auto it:primes){
                long long val=curr*it;
                if(visited.find(val)==visited.end()){
                    pq.push(val);
                    visited.insert(val);
                }


            }
        }
        return curr;
        
    }
};