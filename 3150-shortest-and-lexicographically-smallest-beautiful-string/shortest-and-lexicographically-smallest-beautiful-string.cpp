class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int left=0;
        int right=0;
        int ones=0;
        int length=0;
        while(right<s.size()){
            ones+=(s[right]=='1'?1:0);
            while(ones>k && left<right){
                ones-=(s[left]=='1'?1:0);
                left++;
            }
            if(ones==k){
                int m=left;
                string str=s.substr(left,right-left+1);
                while(m<s.size() && s[m]=='0')m++;
                
                str=s.substr(m,right-m+1);
                if(ans.size()==0){
                    ans=str;
                    length=str.size();
                }
                else if(str.size()<length){
                    ans=str;
                    length=str.size();

                }
                else if(str.size()==length){
                    if(str<ans){
                        ans=str;
                        
                    }
                }
            }
            right++;

        }
        return ans;
        
    }
};