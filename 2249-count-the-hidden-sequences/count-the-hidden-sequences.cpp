class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {
        int maxi=*max_element(difference.begin(),difference.end());
        int mini=*min_element(difference.begin(),difference.end());
        vector<long long>prefix;
        prefix.push_back(3);
        for(int i=0;i<difference.size();i++){
            long long  value=prefix[prefix.size()-1]+difference[i];
            prefix.push_back(value);
            
        }
        sort(prefix.begin(),prefix.end());
        for(auto it:prefix) cout<<it<<" ";
        if(prefix.size()==1){
            return (upper-lower+1)-prefix[0];
        }
        int count= (upper-lower+1)-(prefix[prefix.size()-1]-prefix[0]);
        if(count<0) return 0;
        return count;
        
    }
};