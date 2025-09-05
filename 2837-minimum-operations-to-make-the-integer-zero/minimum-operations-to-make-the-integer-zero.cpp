class Solution {
public:
int count_bit(int value){
    long long cnt=0;
    while(value>0){
        cnt+=(value & 1);
        value>>1;

    }
    return cnt;
}
    int makeTheIntegerZero(int num1, int num2) {

        if(num1<num2)return -1;
        for(int i=1;i<=60;i++){
            long long value=(long long)((long long)num1-(long long)i*num2);
            long long count1=__builtin_popcountll(value);
            if(count1<=i && i<=value)return i;
        }
        return -1;

        

        
    }
};