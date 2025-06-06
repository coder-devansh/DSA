class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }
        vector<vector<int>>ans;
        ans.push_back({1});
        vector<int>nums={1,1};
        ans.push_back(nums);
        for(int i=2;i<numRows;i++){
            vector<int>temp;
            temp.push_back(nums[0]);
            for(int j=1;j<nums.size();j++){
                if(j==0){
                    temp.push_back(nums[j]);
                }else{
                    int val=nums[j-1]+nums[j];
                    temp.push_back(val);
                }


            }
            temp.push_back(nums[nums.size()-1]);
            ans.push_back(temp);
            nums=temp;
            

        }
        return ans;

        
    }
};