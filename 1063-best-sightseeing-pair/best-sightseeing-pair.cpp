class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>vec(values.size(),0);
        int maxi=0;
        // for(int i=0;i<values.size();i++){
        //     maxi=max(maxi,values[i]+i);
        //     vec[i]=maxi;
        // }
        int maxi1=0;
        for(int j=1;j<values.size();j++){
            maxi=max(maxi,values[j-1]+j-1);
            maxi1=max(maxi1,values[j]-j+maxi);
        }
        return maxi1;
        
    }
};