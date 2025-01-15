class Solution {
public:
bool setbit(int result,int bit){
    return result & (1<<bit);
}
    int minimizeXor(int num1, int num2) {
        int value;
        value=num2;
        int count=0;

        while(num2>0){
             if((1 & num2)!=0){
                count++;
             }

            num2=num2>>1;
           
    
        }
        num2=value;
        int count2=0;
    long long  result=num1;
    long long  temp=result;
    while(temp>0){
       if((temp & 1)!=0){
        count2++;
       }
       temp=temp>>1;
    }
    cout<<count<<endl;
    cout<<count2;
    if(count2>count){
        long long  currentbit=0;
        while(count2>count){
            if(setbit(result,currentbit)){
                result=result & ~(1<<currentbit);
                count2--;
            }
            currentbit++;

    }
    }
    else if(count>count2){
        int currentbit=0;
        while(count>count2){
            if(!setbit(result,currentbit)){
                result= result | (1<<currentbit);
                count2++;
            }
            currentbit++;


        }

    }
    
    return result;   
        
    }
};