class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=0;
        while(numBottles>=numExchange){
            int bottles=(numBottles)/numExchange;
            total+=(bottles*numExchange);
            numBottles-=(bottles*numExchange);
            
            numBottles+=bottles;

        }
        total+=(numBottles);
        return total;

        
    }
};