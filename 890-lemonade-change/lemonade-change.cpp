class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       
        int fives=0;
        int tens=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fives++;
            }
            if(bills[i]==10){
                if(fives==0){
                    return false;
                }
                fives--;
                tens++;
            }
            if(bills[i]==20){
                if(fives && tens){
                    fives-=1;
                    tens-=1;
                }else if(fives>=3){
                    fives-=3;
                }else{
                    return false;
                }
            }
        }
        return true;

        
    }
};