#define ll long long
class Solution {
public:
ll find(ll val,vector<int>&arr,int height,int index){
    ll low=1;
    ll high=height;
   ll ans=0;
    while(low<=high){
        ll mid=(low+high)/2;
        ll value=(mid*(mid+1)/2)*1ll*arr[index];
      
        if(value<=val){
           low=mid+1;
            ans=mid;
        }
        if(value>val)high=mid-1;
    }
    return ans;
}
bool canbe(ll val,vector<int>&arr,ll height){
    for(int i=0;i<arr.size();i++){
        height-=find(val,arr,height,i);
        if(height==0)return true;
    }
    return false;

}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        ll low=1;
        ll high=(ll)1e18;
        ll ans=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            if(canbe(mid,workerTimes,mountainHeight)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
        
    }
};