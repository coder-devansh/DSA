class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int amount=-1;
       int startInd=-1;
       int count=0;
       int i=0;
       while(count<2*gas.size()+1){
        if(i==startInd)return startInd;
        if(startInd==-1 && gas[i]>=cost[i]){
            amount=gas[i]-cost[i]+gas[(i+1)%(gas.size())];
            startInd=i;
        }else if(amount<cost[i]){
            if(gas[i]>=cost[i]){
            amount=gas[i]-cost[i]+gas[(i+1)%(gas.size())];
            startInd=i;
                
            }else{
                startInd=-1;
                amount=-1;
            }
        }
        else if(amount>=cost[i]){
            amount=amount-cost[i]+gas[(i+1)%(gas.size())];
        }
        i++;
        i=(i % gas.size());
        count++;
        // cout<<i<<endl;


       }
        
        return -1;
    }
};