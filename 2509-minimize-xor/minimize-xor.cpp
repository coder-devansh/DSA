class Solution {
public:
bool isSet(int result,int bit){
    return result & 1<<bit;
}
    int minimizeXor(int num1, int num2) {
        int value=num2;
        int targetbits=0;
        int setbits=0;
        while(value>0){
            targetbits+=(1 & value);
            value=value>>1;
            

        }
        int result=num1;
        int temp=result;
        while(temp>0){
            setbits+=(1 & temp);
            temp=temp>>1;
        }
        int currentbit=0;
        while(setbits<targetbits){
            if(!isSet(result,currentbit))
            {
                result=result | (1<<currentbit);
                setbits++;



            }
            currentbit++;
        }
        while(setbits>targetbits){
            if(isSet(result,currentbit)){
                result=result & ~(1<<currentbit);
                setbits--;
            }
            currentbit++;
        }
        return result;

        
    }
};