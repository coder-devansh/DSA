class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string str=to_string(i);
            if(str.size()%2==0){
                int left_sum=0;
                for(int i=0;i<str.size()/2;i++){
                    left_sum+=(str[i]-'0');

                }
                int right_sum=0;
                for(int j=str.size()/2;j<str.size();j++){
                    right_sum+=(str[j]-'0');
                }
               
               count+=(left_sum==right_sum);

            }
        }
        return count;
        
    }
};