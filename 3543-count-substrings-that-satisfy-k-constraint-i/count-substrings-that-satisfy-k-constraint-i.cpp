class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        map<int,int>mp;
        int left=0;
        int right=0;
        int count=0;
        while(right<s.size()){
            mp[s[right]-'0']++;
            while(left<right && mp[0]>k && mp[1]>k){
                mp[s[left]-'0']--;
                if(mp[s[left]]==0)mp.erase(s[left]);
                left++;
            }
            if(mp[0]<=k || mp[1]<=k){
                count+=right-left+1;
            }
            right++;
        }
        return count;
        
    }
};