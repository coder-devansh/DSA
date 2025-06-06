class Solution {
public:
    string robotWithString(string s) {
        vector<char>minRight(s.size());
        minRight[s.size()-1]=s[s.size()-1];
        for(int i=s.size()-2;i>=0;i--){
            minRight[i]=min(s[i],minRight[i+1]);
        }
        string t="";
        string paper="";
        int i=0;
        while(i<s.size()){
            t.push_back(s[i]);
            char minChar=(i+1<s.size())?minRight[i+1]:s[i];

            while(!t.empty() && t.back()<=minChar){
                paper+=t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;

    }
};