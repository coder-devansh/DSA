class Solution {
public:
bool check(int low,int high,string &ans){
    while(low<=high){
        if(ans[low]!=ans[high])return false;
        low++;
        high--;
    }
    return true;
}
    string longestPalindrome(string s) {
        int maxLen=0;
        string result="";
        int index=-1;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(i,j,s)){
                    if(maxLen<(j-i+1)){
                        maxLen=j-i+1;
                        index=i;
                    }
                    
                }
                
            


            }
        }
        return s.substr(index,maxLen);
        
    }
};