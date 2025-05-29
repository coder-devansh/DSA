class StockSpanner {
public:

vector<int>arr;
    StockSpanner() {
        arr.clear();

        
    }
    
    int next(int price) {
        stack<int>st;
        arr.push_back(price);
        int count=1;
        for(int i=arr.size()-2;i>=0;i--){
            if(price<arr[i]){
                break;
            }
            count+=1;
        }
        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */