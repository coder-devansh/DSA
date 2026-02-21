class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        int count=0;
        for(int i=left;i<=right;i++){
            int val=i;
            int sum=0;
            while(val){
                if(val & 1)sum++;
                val=val>>1;
            }
            if(sum==0 || sum==1)continue;
            if(sum==2 || sum==3 || sum==5 || sum==7)count++;
            else if(sum%2!=0 && sum%3!=0 && sum%5!=0 && sum%7!=0)count++;
        }
        return count;
        
    }
};