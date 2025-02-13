class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>q;
        double sum=0;
        for(auto it:nums){
            q.push(it);
            sum+=it;
        }

         double target=(double)sum/2;
        long long opr=0;
        while(sum>target){
            auto it=q.top();
            q.pop();
            sum-=(double)(it/2);
            it=(double)it/2;
            q.push(it);
            cout<<it<<endl;
            
            opr++;
        }
        return opr;

        
        
    }
};