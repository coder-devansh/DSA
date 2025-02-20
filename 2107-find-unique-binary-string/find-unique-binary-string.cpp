class Solution {
public:
vector<string>result;
void generate(vector<string>nums,map<string,int>mp,string ans){
    if(ans.size()==nums[0].size()){
        if(mp.find(ans)==mp.end()){
            result.push_back(ans);
        }
        return;
    }
    for(char j='0';j<='1';j++){
        if(result.size()==1){
            break;
        }
        generate(nums,mp,ans+j);


    }

   
}

    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>mp;
        int n;
        for(auto it:nums){
            n=it.size();
            mp[it]++;
        }
        generate(nums,mp,"");
        return result[0];

        
    }
};