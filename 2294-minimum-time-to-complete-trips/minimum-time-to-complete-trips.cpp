class Solution {
public:
bool canBe(vector<int >&time,long long  mid,long long total_trips){
    long long sum=0;
    for(int i=0;i<time.size();i++){
        sum+=(mid/time[i]);
    }
    if(sum>=total_trips)return true;
    return false;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxi=INT_MAX;
        for(auto it:time){
            maxi=min(maxi,(long long)it);
        }
        long long low=1;
        long long high=1e14;
        long long ans=0;
        while(low<=high){
            long long mid=(long long)((low+high)/2);
            if(canBe(time,mid,totalTrips)){
                ans=mid;
                high=mid-1;

            }else{
                low=mid+1;
            }
        }
        if(ans==0)return maxi*totalTrips;
        return ans;
        
    }
};