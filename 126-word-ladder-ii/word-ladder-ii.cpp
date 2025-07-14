class Solution {
public:
 unordered_map<string,int>mp;
 vector<vector<string>>result;
void dfs(string word,string beginWord,vector<string>&words,int steps){
    if(word==beginWord){
        reverse(words.begin(),words.end());
        result.push_back(words);
        reverse(words.begin(),words.end());
        return ;
    }
    for(int i=0;i<word.size();i++){
        char original=word[i];
        for(char ch='a';ch<='z';ch++){
            word[i]=ch;
            if(mp.find(word)!=mp.end() && mp[word]==steps-1){
                words.push_back(word);
                dfs(word,beginWord,words,steps-1);
                words.pop_back();


            }
        }
        word[i]=original;

    }
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>st;
        mp[beginWord]=0;
        for(auto it:wordList)st.insert(it);
        if(st.find(endWord)==st.end())return {};
       
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        st.erase(beginWord);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string word=it.first;
            int steps=it.second;
            if(word==endWord)break;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        mp[word]=steps+1;
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        vector<string>words={endWord};
        dfs(endWord,beginWord,words,mp[endWord]);
        return result;

        
    }
};