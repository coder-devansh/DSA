class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char,int>mp;
        for(auto it:p){
            mp[it]++;
        }
        map<char,int>compare;
       int left=0;
       int right=0;
       vector<int>ans;
       while(right<s.size()){
         compare[s[right]]++;
         while(mp[s[right]]<compare[s[right]]){
            compare[s[left]]--;
            if(compare[s[left]]==0)compare.erase(s[left]);
            left++;
         }
         if(mp==compare){
            ans.push_back(left);
         }
         right++;
       }
       return ans;
        
    }
};