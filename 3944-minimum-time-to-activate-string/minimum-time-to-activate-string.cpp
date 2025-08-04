class Solution {
public:
bool isValid(string s,vector<int>&order,int k,long long mid){
    for(int i=0;i<=mid;i++){
        s[order[i]]='*';
    }
    long long lastCharIndex=-1;
    long long count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*')
        {
            lastCharIndex=i;
        }
        if(lastCharIndex!=-1){
            count+=lastCharIndex+1;
        }

    }
    return count>=k;
}
    int minTime(string s, vector<int>& order, int k) {
        long long  low=0;
        long  high=order.size()-1;
        long long  ans=-1;
        while(low<=high){
            long long  mid=low+(high-low)/2;
            if(isValid(s,order,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};