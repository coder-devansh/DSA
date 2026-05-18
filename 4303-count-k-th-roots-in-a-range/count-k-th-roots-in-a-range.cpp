class Solution {
public:
bool power(long long base,long long exp,int r){
    long long ans=1;
    while(exp>0){
        if(exp%2!=0){
            ans=ans*base;
            if(ans>r)return false;
            
            exp--;
        }else{
            base=base*base;
            if(base>r)return false;
           
            exp=exp/2;
        }
    }
    return true;
}
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return (r-l+1);
        }
        
        long long count=0;
        for(int i=0;i<=r;i++){
            if(power(i,k,r)){
                if(pow(i,k)>=l){
                count++;
                }
            }else{
                break;
            }
        }
        return count;

        
    }
};