class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        int k=2;
        int left=0;
        int right=0;
        int mini=INT_MAX;
        while(right<s.size()){
            mp[s[right]]++;
            if(mp[s[right]]==3){
                int i=right;
                char ch=s[i];
            while(mp[ch]>1 && i>=0){
               if(s[i]==ch){
                  mp[s[i]]--;

               }
              
                
                i--;
            }
          
        }
            
                right++;
            }
            string ans="";
            for(auto it:mp){
                for(int i=0;i<it.second;i++){
                    ans+=it.first;
                }
            }
            return ans.size();
            
        
        if(mini==INT_MAX){
            return s.size();
        }
        return mini;
        
    }
};