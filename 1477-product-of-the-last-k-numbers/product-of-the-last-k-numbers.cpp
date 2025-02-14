class ProductOfNumbers {
public:

   vector<long long>arr;
   vector<long long>product{1};

    ProductOfNumbers() {
        
        
        
    }
    
    void add(int num) {
        arr.push_back(num);
        if(num==0){
            product.clear();
            product.push_back(1);
           
        }else{
              product.push_back(num*product.back());
        }
        

        
        
        
    }
    
    int getProduct(int k) {
        return k < product.size() ? product.back() / product[product.size() - k - 1] : 0;


        
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */