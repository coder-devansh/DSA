class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str=to_string(n);
        bool found=true;
        for(int i=1;i<str.size();i++){
            if(str[i-1]>str[i])found=false;

        }
        if(found)return n;
        int point=-1;
        found=true;
        for(int i=1;i<str.size();i++){
            if(str[i-1]<=str[i] && found){
               int val1=str[i-1]-'0';
               int val2=str[i]-'0'-1;
               if(val1<=val2)point=i;
            }
            if(str[i-1]>str[i])found=false;
        }
        
        string ans="";
        if(point==-1 && str[0]=='1'){
            for(int i=1;i<str.size();i++){
                ans+='9';
            }
            return stoll(ans);

        }
        else if(point==-1){
            ans+=to_string(str[0]-'0'-1);
            for(int i=1;i<str.size();i++){
                ans+='9';
            }
            return stoll(ans);
        }
        else{
            for(int i=0;i<str.size();i++){
                if(i<point){
                    ans+=str[i];
                }
                else if(i==point){
                    ans+=to_string(str[i]-'0'-1);
                }else{
                    ans+='9';
                }
            }
            return stoll(ans);
        }
        
    }
};