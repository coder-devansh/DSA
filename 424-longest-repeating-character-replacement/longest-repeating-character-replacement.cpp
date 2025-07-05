class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0;
        int left=0;
        int max_length=0;
        map<char,int>mp;
        char max_character='c';
        int max_count=0;
        while(right<s.size()){
           mp[s[right]]++;
           max_count = max(max_count, mp[s[right]]);
           while((right-left+1)-max_count>k){
            mp[s[left]]--;
            if(mp[s[left]]==0)mp.erase(s[left]);
            left++;
           }
           max_length=max(max_length,right-left+1);
           right++;

        }
        return max_length;
        

    }
};