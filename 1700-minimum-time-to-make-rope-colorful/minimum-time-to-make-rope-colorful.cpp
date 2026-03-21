class Solution {
public:
    int minCost(string color, vector<int>& needTime) {
        int time=0;
        int i=0;
        int j=1;
        while(i<color.size() && j<color.size()){
            if(i!=j && color[i]==color[j]){
                int max_val=needTime[i];
                 int sum=0;
                sum+=needTime[i];
               
               while(j<color.size() && color[i]==color[j]){
                sum+=needTime[j];
                max_val=max(max_val,needTime[j]);
                j++;
               }
               i=j;
               time+=(sum-max_val);
                

            }
            else if(i!=j && color[i]!=color[j]){
                i++;
                j++;
            }
                else{
                
                j++;
            }
        }
        return time;
        
    }
};