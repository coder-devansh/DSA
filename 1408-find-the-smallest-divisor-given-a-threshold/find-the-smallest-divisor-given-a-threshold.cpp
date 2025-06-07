class Solution {
public:
bool canPossible(int mid,vector<int>&piles,int h){
    int count=0;
    for(auto it:piles){
        count+=ceil(1.0 * it/mid);

    }
    return count<=h;;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<high){
            int mid=(low+(high-low)/2);
            if(canPossible(mid,nums,threshold)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};