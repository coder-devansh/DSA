class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {
        vector<long long>prefix;
        prefix.push_back(3);
        long long maxi=3;
        long long  mini=3;
        for(const auto&it:difference){
            long long  value=prefix[prefix.size()-1]+it;
            prefix.push_back(value);
            maxi=max(maxi,value);
            mini=min(mini,value);
            
        }
        int count= (upper-lower+1)-(maxi-mini);
        if(count<0)return 0;
        return count;
        
    }
};