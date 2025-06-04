class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;

        }
        nums.clear();
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                nums.push_back(it.first);

            }
        }
        
    }
};