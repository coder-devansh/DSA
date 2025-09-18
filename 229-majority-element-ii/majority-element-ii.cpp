class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candi1=-1;
        int candi2=-1;
        int vote1=0;
        int vote2=0;
        for(int i=0;i<nums.size();i++){
            if(candi1 == nums[i])vote1++;
            else if(candi2 == nums[i])vote2++;
            else if(vote1 == 0){
                candi1 = nums[i];
                vote1 = 1;
            } 
            else if(vote2 == 0){
                candi2 = nums[i];
                vote2 = 1;
            } 
            else{
                vote1--;
                vote2--;
            }
        }
        int c1=0;
        int c2=0;
        for(auto it:nums){
            if(it==candi1)c1++;
            else if(it==candi2)c2++;
        }
        vector<int>ans;
        if(c1>float(nums.size()/3))ans.push_back(candi1);
        if(c2>float(nums.size()/3))ans.push_back(candi2);
        return ans;
        
    }
};