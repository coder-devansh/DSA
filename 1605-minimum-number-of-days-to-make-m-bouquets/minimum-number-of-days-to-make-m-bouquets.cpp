class Solution {
public:
int canPossible(int mid,vector<int>&bloomDay,int m,int k){
    int bouquets=0;
    int flower=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]>mid){
            flower=0;
        }

        if(bloomDay[i]<=mid)
        {
            flower++;

        }
        
        if(flower==k){
            bouquets++;
            flower=0;
        }
    }
    return bouquets;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(canPossible(mid,bloomDay,m,k)>=m){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            } 
        }
        return (ans==INT_MAX)?-1:ans;

        
    }
};