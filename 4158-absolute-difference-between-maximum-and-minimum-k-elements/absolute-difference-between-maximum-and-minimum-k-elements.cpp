class Solution {
public:
    static bool compare(const int& a,const int b){
        return a>b;
        
    }
    int absDifference(vector<int>& nums, int k) {
        if(k==nums.size()){
            return 0;
        }
        vector<int>copy=nums;
        sort(nums.begin(),nums.end(),compare);
        sort(copy.begin(),copy.end());
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            
            
        }
        long long sum2=0;
        for(int i=0;i<k;i++){
            sum2+=copy[i];
            
        }
        return abs(sum-sum2);
    }
};