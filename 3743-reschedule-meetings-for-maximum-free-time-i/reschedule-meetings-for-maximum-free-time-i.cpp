class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& start, vector<int>& end) {
        vector<int>freetime;
        freetime.push_back(start[0]-0);
        for(int i=0;i<start.size()-1;i++){
            freetime.push_back(start[i+1]-end[i]);
        }
        int size=k+1;
        int right=0;
        int left=0;
        int sum=0;
        int maxi=0;
        freetime.push_back(eventTime-end[end.size()-1]);
        if(freetime.size()<size){
            return accumulate(freetime.begin(),freetime.end(),0);
        }
        
        while(right<freetime.size()){
            sum+=freetime[right];
            while(right-left+1>size){
                sum-=freetime[left];
                left++;
            }
            if(right-left+1==size){
                maxi=max(maxi,sum);
            }
            right++;
            
        }
        return maxi;
        
    }
};