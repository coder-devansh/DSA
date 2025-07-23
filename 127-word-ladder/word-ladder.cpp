class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        set<string>used;

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int dist=q.front().second;
            if(word==endWord)return dist;
            q.pop();
            for(int i=0;i<word.size();i++){
            char original=word[i];
            
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end() && used.find(word)==used.end()){
                        used.insert(word);
                        q.push({word,dist+1});
                    }

                    


                }
                word[i]=original;
            }
        }
        return 0;
        
    }
};