class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>dominant;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       
        for(int i=0;i<nums.size()-1;i++){
            dominant[nums[i]]++;
           if((2*dominant[nums[i]])>(i-0+1)){
               int f=mp[nums[i]]-dominant[nums[i]];
               if(2*f>(nums.size()-(i+1)))
               {
                return i;
               }
           }
                

            
        }
        return -1;

        
        
    }
};