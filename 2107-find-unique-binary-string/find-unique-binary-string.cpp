class Solution {
public:
string find(int i,int n,string str,unordered_map<string,int>&mp){
    if(i==n){
        if(mp.find(str)==mp.end())return str;
        else return "-1";

    }
    auto left=find(i+1,n,str+'0',mp);
    auto right=find(i+1,n,str+'1',mp);
    if(left!="-1" )return left;
    if(right!="-1")return right;
    return left;

}
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mp;
        for(auto it:nums)mp[it]++;
        int n=nums[0].size();
        return find(0,n,"",mp);
        
        
    }
};