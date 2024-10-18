class Solution {
public:
vector<int>output;
int count;
void generate(int i,vector<int>nums,vector<vector<int>>&ans,int maxi){
    if(i==nums.size()){
        int result=0;
        if(output.size()!=0){
            for(int j=0;j<output.size();j++){
            result=result | output[j];

        }
        
                  
        }
        if(result==maxi){
            count++;
        }
        
        return;
    }
    output.push_back(nums[i]);
    generate(i+1,nums,ans,maxi);
    output.pop_back();
    generate(i+1,nums,ans,maxi);
   


}
    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int>mp;
        int maxi=0;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            maxi=maxi | nums[i];

           
        }
        
        generate(0,nums,ans,maxi);
        return count;
    }
};