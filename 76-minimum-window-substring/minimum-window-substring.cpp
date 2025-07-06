class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>t_map;
        for(auto it:t){
            t_map[it]++;
        }
        int required=t_map.size();
        int formed=0;
        map<char,int>s_map;
        int right=0;
        int left=0;
        int mini=INT_MAX;
        string ans;
        int start=0;
        
        while(right<s.size()){
            char c=s[right];
            s_map[c]++;
            if(t_map.count(c) && s_map[c]==t_map[c]){
                formed++;
            }
            while(formed==required){
                int length=right-left+1;
                while(length<mini){
                  
                   start=left;
                   mini=length;
                }

                //shrink from the left
                char ch=s[left];
                s_map[ch]--;
                if(s_map[ch]==0)s_map.erase(ch);
                if(s_map[ch]<t_map[ch])formed--;
                left++;
            }
            right++;
            
            
        }

        return mini==INT_MAX?"":s.substr(start,mini);

        
    }
};