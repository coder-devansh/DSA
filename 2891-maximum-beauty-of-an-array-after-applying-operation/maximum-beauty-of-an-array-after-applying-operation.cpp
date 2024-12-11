class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int r=0;
        int l=0;
        int maxi=0;
        map<int,int>mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(l<r && (nums[r]-nums[l])>2*k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            
            int size=mp.size();
            cout<<size<<endl;
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
        
        
    }
};