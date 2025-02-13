class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
     priority_queue<long long, vector<long long>, greater<long long>>q;

    // Push some elements
    for(auto it:nums){
        q.push(it);
    }
    long long opr=0;
    while(q.size()>=2){
        long long element=q.top();
        q.pop();
        long long value=q.top();
        q.pop();
        if(element>=k && value>=k){
             return opr;
        }
        else{
            q.push(min(element,value)*2+max(element,value));
            opr++;
        }
        
        }
        return opr;

       


        
    }
};