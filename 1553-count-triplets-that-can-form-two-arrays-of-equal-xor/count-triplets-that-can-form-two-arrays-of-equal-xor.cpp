class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>prefix(arr.size());
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        int count=0;
       for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            for(int k=j;k<arr.size();k++){
                if(i>0){
                    int a=prefix[j-1]^prefix[i-1];
                    int b=prefix[k]^prefix[j-1];
                    if(a==b)count++;
                }else{
                    int a=prefix[j-1];
                    int b=prefix[k]^prefix[j-1];
                    if(a==b)count++;
                }
            }
        }
       }
        return count;

        
    }
};