class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int max_count=INT_MIN;
        for(auto it:nums){
            mp[it]++;
        }
        int start=0;
        int count=0;
        for(auto it:mp){
            if(it.first==start){
                count++;
            }else{
                max_count=max(max_count,count);
                count=1;
                start=it.first;
            }
            start++;
        }
        max_count=max(max_count,count);
        return max_count;

    }
};