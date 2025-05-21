class Solution {
public:
bool isBananas(vector<int>&piles,int mid,int h){
    int hour=0;
    for(auto it:piles){
        hour+=ceil((double)it/mid);
    }
    return hour<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        sort(piles.begin(),piles.end());
        int right=piles[piles.size()-1];
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(isBananas(piles,mid,h)){
                right=mid;
            }else{
                left=mid+1;
            }
        }

return left;
        
    }
};