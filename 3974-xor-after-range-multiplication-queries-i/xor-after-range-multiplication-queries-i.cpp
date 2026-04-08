#define ll long long
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=(int)1e9+7;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            for(int m=l;m<=r;m+=k){
                nums[m]=(ll)(nums[m]*1ll*v)%(mod);
            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;

        
    }
};