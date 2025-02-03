class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0){
            return nums.size();
        }
        int asc=1;
        int desc=1;
        int maxi_desc=0;
        int maxi_asc=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])
            {
                maxi_desc=max(maxi_desc,desc);
                desc=1;

                asc++;
            }else if(nums[i]>nums[i+1])
            {
                maxi_asc=max(maxi_asc,asc);
                asc=1;
                desc++;
            }else{
                maxi_desc=max(maxi_desc,desc);
        maxi_asc=max(maxi_asc,asc);
                
                asc=1;
                desc=1;
            }
        }
        maxi_desc=max(maxi_desc,desc);
        maxi_asc=max(maxi_asc,asc);
       if(max(maxi_asc,maxi_desc)==0){
        return 1;
       }
       return max(maxi_asc,maxi_desc);
        
    }
};