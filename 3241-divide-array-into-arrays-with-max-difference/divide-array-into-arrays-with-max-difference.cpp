class Solution {
public:
vector<vector<int>>result;
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>result;
        bool found=true;
        int i=0;
        while(i<nums.size()){
            int count=0;
            vector<int>ans;
            while(count<=2 && i<nums.size()){
                if(ans.size()==0){
                    ans.push_back(nums[i]);

                }else if((nums[i]-ans[0])<=k){
                        ans.push_back(nums[i]);
                }
                else{
                    found=false;
                    break;
                    
                }
                count++;
                i++;

                
            }
            if(ans.size()==3){
                result.push_back(ans);
            }
        }
        if(found==true){
            return result;
        }
        return {};

        
    }
};