class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        map<int,int>mp;
        for(auto it:nums) mp[it]++;
        int i=0;
        int count=0;
        int maxi=0;
        for(auto it:mp){
            if(it.first==i){
                count++;
            }else{
                maxi=max(maxi,count);
                i=it.first;
                count=1;
            }
            i++;

        }
        maxi=max(maxi,count);
      return maxi;


        
    }
};