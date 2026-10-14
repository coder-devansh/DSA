class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum<=9){
            string ans="";
            ans+=to_string(sum);
            num--;
            while(num--){
                ans+='0';
            }
            return ans;
        }
        if(num==1 && sum>9)return "";
        string ans="";
        while(sum>=9 && num){
            ans+='9';
            num--;
            sum-=9;

        }
        if(num>=1)
        {
            ans+=to_string(sum);
            sum-=sum;
            num--;
        }
        while(num--){
            ans+='0';
        }
        if(sum==0)return ans;
        return "";
        
    }
};