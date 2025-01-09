class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        long long count=0;
        for(int i=0;i<words.size();i++){
            if(words[i].size()>=pref.size()){
                string prefix=words[i].substr(0,pref.size());
                if(prefix==pref){
                    count++;
                }
            }

        }
        return count;
        
    }
};