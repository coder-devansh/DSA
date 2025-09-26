class Solution {
public:
bool canbepossible(vector<int>dist,int mid,double hour){
    double h=0;
    for(int i=0;i<dist.size();i++){
        if(i==dist.size()-1){
            h+=(dist[i]*1.0/mid);
        }else{
            h+=ceil(dist[i]*1.0/mid);
        }
    }
    cout<<h<<endl;
    return h<=hour;

}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(canbepossible(dist,mid,hour)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
       return (ans==INT_MAX)?-1:ans;
        
    }
};