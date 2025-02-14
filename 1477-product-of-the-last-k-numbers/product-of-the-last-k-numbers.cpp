class ProductOfNumbers {
public:

   vector<long long>arr;
   vector<long long>product;
    ProductOfNumbers() {
        arr.clear();
        
        
        
    }
    
    void add(int num) {
        arr.push_back(num);
        
        
    }
    
    int getProduct(int k) {
        long long product=1;
        int i=arr.size()-1;

        int count=0;
        while(i>=0 && count<k){
            product*=arr[i];
            i--;
            count++;

        }
        return product;


        
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */