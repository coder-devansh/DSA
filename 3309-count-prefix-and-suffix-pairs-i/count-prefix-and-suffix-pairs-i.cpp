class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        long long count=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                string word1=words[i];
                string word2=words[j];
                if(i<j && word1.size()<=word2.size())
                {
                    string prefix=word2.substr(0,word1.size());
                    string suffix=word2.substr(word2.size()-word1.size());
                    if(prefix==word1 && suffix==word1)
                    {
                        count++;
                    }
                    cout<<prefix<<endl;
                    cout<<suffix<<endl;
                    
                }
            }
        }
        return count;
        
    }
};