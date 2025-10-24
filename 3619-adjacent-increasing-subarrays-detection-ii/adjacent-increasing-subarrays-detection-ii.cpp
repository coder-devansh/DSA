// we can use binary search
// now we have to find the strictly increasing subary of 2*k;
class Solution {
public:
int canbe(int mid,vector<int>&suffix){
        for(int i=1;i<suffix.size()-1;i++){
        if((i-mid)+1<0)continue;
        int val=suffix[(i-mid)+1];
        int val1=suffix[i+1];
       if(val>=mid && val1>=mid){
        return true;
       }
        




    }
    return false;
   
}
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>suffix(nums.size(),0);
    suffix[nums.size()-1]=1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            suffix[i]=suffix[i+1]+1;
        }else{
            suffix[i]=1;
        }
    }
        int low=1;
        int high=nums.size();
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            bool flag=canbe(mid,suffix);
             if(flag){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;

        
    }
};