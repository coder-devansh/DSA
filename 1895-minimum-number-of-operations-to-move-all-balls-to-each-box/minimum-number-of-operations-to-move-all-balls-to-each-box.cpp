   class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);

        for(int i=0;i<boxes.size();i++){
            long long sum=0;
            for(int j=0;j<boxes.size();j++){
                if(boxes[j]=='1')
                {
                    sum+=abs(i-j);
                }
            }
            ans[i]=sum;

        }
        return ans;
        
    //    vector<int>prefix(boxes.size(),0);
    //    vector<int>suffix(boxes.size(),0);
    //    long long sum=0;
    //    for(int i=boxes.size()-1;i>=0;i--){
    //     sum+=boxes[i]-'0';
    //     prefix[i]=sum;
    //    }
    //    sum=0;
    //    vector<int>ans(boxes.size(),0);
    //    for(int i=0;i<boxes.size();i++){
    //     sum+=boxes[i]-'0';
    //     suffix[i]=sum;
    //    }
    //    for(int i=0;i<boxes.size();i++){
           
    //    }
    //    return ans;
        
    }
};