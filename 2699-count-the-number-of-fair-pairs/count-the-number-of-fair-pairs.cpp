class Solution {
public:
int find_lower(vector<int>&arr,int target,int turn,int i){
    int low=i;
    int high=arr.size()-1;
    int ans=-1;
    if(turn==0){
         while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[mid]<target){
            ans=mid;
            low=mid+1;

        }else{
            high=mid-1;
        }
    }

    }
    if(turn==1){
          while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[mid]<=target){
            ans=mid;
            low=mid+1;

        }else{
            high=mid-1;
        }
    }

    }
    return ans;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int count=0;
        sort(nums.begin(),nums.end());
        long long  res=0;
        for(int i=0;i<nums.size();i++)
        {
            int target=lower-nums[i];
            
           int j=find_lower(nums,target,0,i);
           if(j!=-1){
            res+=j-i;

           }
           
        }
        long long  res1=0;
         for(int i=0;i<nums.size();i++)
        {
            int target=upper-nums[i];
            int j=find_lower(nums,target,1,i); 
            if(j!=-1){
                 res1+=j-i;

            }           
           
        }
        return (long long)res1-res;


        
    }
};