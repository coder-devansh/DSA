class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>curr;
        for(int i=0;i<nums.size();i++){
            curr.push_back(nums[i]);
        }
        int n=nums.size();
        while(n--){
            vector<int>prev;
            for(int i=0;i<curr.size();i++){
                if(i+1<curr.size()){
                    prev.push_back((curr[i]+curr[i+1])%10);
                }

            }
            if(prev.size()==1){
                return prev[0];
            }
            curr=prev;
        }
        return -1;
        


        
    }
};