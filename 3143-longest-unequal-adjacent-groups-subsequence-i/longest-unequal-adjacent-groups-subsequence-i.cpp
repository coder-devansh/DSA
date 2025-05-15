class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int i=1;
        ans.push_back(words[0]);
        while(i<words.size()){
            if(groups[i-1]!=groups[i]){
                ans.push_back(words[i]);
            }
            i++;

        }
        return ans;
        
    }
};