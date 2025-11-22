class Solution {
public:
    int minimumFlips(int n) {
        string ans="";
        while(n>0){
            int rem=n%2;
            if(rem==1){
                ans+='1';
            }else{
                ans+='0';
            }
            n=n/2;
        }
        string check=ans;
        int count=0;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=check[i])count++;
        }
        return count;
        
        
        
    }
};