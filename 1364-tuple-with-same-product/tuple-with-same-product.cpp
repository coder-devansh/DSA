class Solution {
public:

    int tupleSameProduct(vector<int>& nums) {
        vector<long long >product;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j])
                {
                    product.push_back(nums[i]*nums[j]);
                }

            }
        }
        sort(product.begin(),product.end());
        int pairofEqualProduct=1;
        long long lastProductSeen=-1;
        int sameProductCount=0;
        int totalNumberOfTuples=0;
        for(int i=0;i<product.size();i++){
            if(product[i]==lastProductSeen){
                sameProductCount++;
            }
            else{
                pairofEqualProduct=(sameProductCount-1)*sameProductCount/2;
                totalNumberOfTuples+=8*pairofEqualProduct;
                lastProductSeen=product[i];
                sameProductCount=1;
            }

        }
        pairofEqualProduct=(sameProductCount-1)*sameProductCount/2;
        totalNumberOfTuples+=8*pairofEqualProduct;
        return totalNumberOfTuples;

        
    }
};