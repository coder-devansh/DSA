class Solution {
public:
// string word=ans.substr(0,,end);
    int countPrefixSuffixPairs(vector<string>& words) {
        long long count=0;

        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++)
            {
                string word1=words[i];
                string word2=words[j];
                if(word1.size()<=word2.size()){
                    string prefix=word2.substr(0,word1.size());
                    string suffix=word2.substr(word2.size()-word1.size());
                    if(prefix==word1 && suffix==word1){
                        count+=1;
                    }
                }


            }
        }
        return count;
        
    }
};