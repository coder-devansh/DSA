class Solution {
public:
bool canwe(int mid,vector<int>nums,int k){
    int count=0;
     for(auto it:nums){
        count+=(it-1)/mid;

     }
     return count<=k;

}
    int minimumSize(vector<int>& nums, int k) {
        
        int maxi=0;
        for(auto it:nums){
            maxi=max(maxi,it);
        }
        int low=1;
        int high=1e9;
        while(low<high){
            int mid=(low+high)/2;
            if(canwe(mid,nums,k)==true){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return high;
        
    }
};