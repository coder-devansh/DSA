class Solution {
public:
    bool canPlaceFlowers(vector<int>&bed, int n) {
        if(n>bed.size()){
            return 0;
        }
        if(n==0){
            return true;
        }
        int len=bed.size();
        if(len==1){

            return bed[0]==0;
        }
        if(bed[0]==0 && bed[1]==0){
            bed[0]=1;
           n--;
        }
        for(int i=1;i<len-1;i++){
            if(bed[i]==0 && bed[i-1]==0 && bed[i+1]==0){
                bed[i]=1;
                n--;
            }
            
        }
        if(bed[len-2]==0 && bed[len-1]==0){
            n--;
        }
        if(n<=0){
            return true;
        }
        return false;
        
    }
};