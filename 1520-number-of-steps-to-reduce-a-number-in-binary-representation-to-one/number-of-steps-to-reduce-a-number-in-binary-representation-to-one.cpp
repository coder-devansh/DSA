class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1){
            if(s[s.size()-1]=='1'){
                bool found=false;
                s[s.size()-1]='0';
                for(int i=s.size()-2;i>=0;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        found=true;
                        break;
                    }
                     if(s[i]=='1'){
                        s[i]='0';
                     }
                }
                
                   
                    if(!found){
                        s=s+"0";
                    }
                    ans++;


                
            }else{
                ans++;
                s.pop_back();
            }
        }
        return ans;
        
    }
};