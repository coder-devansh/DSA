class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
       int l=0;
       int r=0;
       vector<int>result;
      for(int i=0;i<prices.size();i++){
        int found=1;
        for(int j=i;j<prices.size();j++){
            if(j>i && prices[i]>=prices[j]){
                result.push_back(prices[i]-prices[j]);
                found=0;
                break;
            }
        }
        if(found==1){
            result.push_back(prices[i]);
        }
      }
      
      
      
       return result;

    }
};