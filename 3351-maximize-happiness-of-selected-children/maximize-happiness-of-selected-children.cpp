class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long score=0;
        int count=0;
        for(auto it:happiness){
            if(count==k)break;
            score+=max(0,it-count);
            count++;

        }
        return score;


        
    }
};