class Solution {
public:
bool canPossible(int mid,vector<int>&piles,int h){
    long long count=0;
    for(auto it:piles){
        count+=ceil(1.0 * it/mid);

    }
    return count<=h;;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        long long ans=0;
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(canPossible(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

        
    }
};