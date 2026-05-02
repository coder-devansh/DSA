// o*4+1*3+2*2+3*6
// 0*3+1*2+3*6+4*4


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int>prefix_sum(nums.size()+1,0);
        prefix_sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        long long sum=0;
        long long total_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            total_sum+=(nums[i]*i);
        }
        cout<<total_sum<<" ";
        long long maxi=LLONG_MIN;
        maxi=max(maxi,total_sum);
        for(int i=1;i<nums.size();i++){
            total_sum-=nums[i];
            total_sum+=(nums[i-1]*(nums.size()-1));
            total_sum-=(prefix_sum[nums.size()-1]-prefix_sum[i]);
            if(i-2>=0){
                total_sum-=prefix_sum[i-2];
            }
            cout<<total_sum<<" ";
            maxi=max(maxi,total_sum);
        }
        return maxi;


        

        
    }
};