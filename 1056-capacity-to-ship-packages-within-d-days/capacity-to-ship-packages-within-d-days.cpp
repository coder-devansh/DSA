class Solution {
public:
bool canbePossible(vector<int>&weights,int mid,int days){
    int sum=0;
    int ans=1;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
        if(sum>mid){
            sum=weights[i];
            ans+=1;
            if(ans>days){
                return false;
            }
        }

    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=0;
        for(auto it:weights){
            right+=it;
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(canbePossible(weights,mid,days)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;

        
    }
};