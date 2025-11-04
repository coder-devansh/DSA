class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         vector<int>arr(nums.size(),1);
        int maxi=0;
        int last=0;
        vector<int>count(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(arr[i]<arr[j]+1){
                        arr[i]=arr[j]+1;
                        count[i]=count[j];
                    }else if(arr[i]==arr[j]+1){
                        count[i]+=count[j];
                        arr[i]=arr[j]+1;
                    }
                    
                }
            }
            if(maxi<arr[i]){
                last=i;
                maxi=arr[i];
            }
        }
        int result=0;
        for(int i=0;i<arr.size();i++){
            if(maxi==arr[i]){
                result+=count[i];
            }
        }
        
       return result;
        
    }
};