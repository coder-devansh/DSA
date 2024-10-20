class Solution {
public:
    int minOperations(vector<int>& copy) {
    
        int value=copy[copy.size()-1];
        int found=0;
        for(int i=0;i<copy.size()-1;i++)
        {
            if(copy[i]>copy[i+1]){
                found=1;
            }
        }
        if(found==0){
            return 0;
        }
        
       
        int count=0;
        int turn =0;
        for(int i=copy.size()-2;i>=0;i--){
            if(copy[i]>copy[i+1]){
                for(int j=2;j*j<=copy[i];j++){
                    if(copy[i]%j==0){
                        value=j;

                            copy[i]=j;
                              count+=1;
                              turn=1;
                              break;
                              

        
                      
                        
                    }
                    
                }
            }
      

        }
        
        for(int i=0;i<copy.size()-1;i++){
            if(copy[i]>copy[i+1])
            {
                return -1;
            }

        }
        
        return count;
        
    }
};