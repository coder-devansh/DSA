class Solution {
public:
    string triangleType(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        if(mp.size()==1){
            return "equilateral";
        }
        if(mp.size()==3){
            int sum=0;
            for(auto it:mp){
                sum+=it.first;
            }
            for(auto it:nums){
                if(it>=(sum-it)){
                    return "none";
                }
            }

            
            return "scalene";
        }
        else{
            int sum=0;
            for(auto it:nums){
                sum+=it;
            }
            for(auto it:nums){
                if(it>=(sum-it)){
                    return "none";
                }
            }

            return "isosceles";
        }
        return "";
        
    }
};