class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0){
            return -1;
        }
        int count=1;
        int x=1;
        if(x%k==0){
            return 1;
        }
        while(x!=0){
            x=(x*10+1)%k;
            count++;

            

        }
        return count;
        
        
    }
};