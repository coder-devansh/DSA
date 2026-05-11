class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            string str=to_string(it);
            if(str.size()==1)ans.push_back(it);
            else for(auto it:str){
                ans.push_back(it-'0');

            }
        }
        return ans;
        
    }
};