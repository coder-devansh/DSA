class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(auto it:words){
               string str=it;
                string result="";
                
                result+=str[1];
                result+=str[0];
               
                if(mp[result]>0){
                    ans+=4;
                    mp[result]--;
                    if(mp[result]==0){
                        mp.erase(result);
                    }
                }else{
                    mp[str]++;
                }
            }
        
        for(auto it:mp){
            string str=it.first;
            if(str[0]==str[1] && it.second>0){
                ans+=2;
                break;
            }
        }
        return ans;
       
        
    }
};